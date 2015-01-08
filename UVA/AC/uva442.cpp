/*用栈来处理表达式，应该是一种通用的办法，后续总结
　遇到')'时弹出两个元素计算，再压入栈内*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月08日 星期四 09时35分37秒
 & File Name: uva442.cpp
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <utility>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef map<string,int> MSI;
typedef map<int,int> MII;
typedef pair<int,int> PII;

#define LEN(n) (int)log10(n)+1
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
#define F(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Fd(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Fit(i,a) for(__typeof((a).begin()) i=a.begin(); i!=(a).end(); ++i)
#define SET(a,t) memset((a),(t),sizeof(a))
#define SETS(ST) while(!ST.empty()) ST.pop();
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

//#define DEBUG
#ifdef DEBUG
	#define debug(args...) do{cerr<<#args<<":"; dbg,args; cerr<<endl;}while(0)
	#define OK puts("OK")
	#define C(a) cout<<"~~"<<a<<"~~"<<endl
	#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;}
struct debugger{
	template<typename T> debugger& operator , (const T& v){
		cerr<<v<<" ";
		return *this;
	}
} dbg;
#else
	#define debug(args...)
	#define OK
	#define C(a)
	#define PM(a,x,y)
#endif

//#define FRE
#ifdef FRE
	#define FRER freopen("test","r",stdin)
	#define FREW freopen("1","w",stdout)
#else
	#define FRER
	#define FREW
#endif

const int mv4[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int mv8[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const int inf = 0x7fffffff;
const int _inf= 0x8fffffff;
const LL  INF = 1e18;
const double EPS = 1e-8;
const double pi = acos(-1.0);

double ROUNDF(double x,int n){
	double t1,t2=modf(x,&t1);
	double t3=pow(10,n);
	long t4=long(t2*t3+0.5);
	x=t1+t4/t3;
	return x;
}

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

/*-----  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux  -----*/

struct matrix{
	int a,b;
	matrix(int a=0,int b=0):a(a),b(b){}
} m[30];

stack<matrix> st;

int main()
{
	FRER;
	//FREW;
	int n;
	scanf("%d",&n);
	F(i,0,n-1){
		char ch[3];
		scanf("%s",ch);
		scanf("%d %d",&m[ch[0]-'A'].a,&m[ch[0]-'A'].b);
		//debug(ch[0],m[ch[0]-'A'].a,m[ch[0]-'A'].b);
	}
	getchar();
	char s[12345];
	while(scanf("%[^\n]%*c",s)==1){
		int len=strlen(s)-1,ans=0;
		bool error=false;
		F(i,0,len){
			if(s[i]=='(') continue;
			if(s[i]==')'){
			   matrix m2=st.top();st.pop();
			   matrix m1=st.top();st.pop();
			   if(m1.b!=m2.a){
				   error=true;
				   break;
			   }
			   ans+=m1.a*m1.b*m2.b;
			   st.push(matrix(m1.a,m2.b));
			   continue;
			}
			st.push(m[s[i]-'A']);
		}
		error?puts("error"):printf("%d\n",ans);
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}




