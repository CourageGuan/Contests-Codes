/*自己都搞不清题目逻辑，卒*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月21日 星期三 10时28分30秒
 & File Name: uva127.cpp
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

#define DEBUG
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

#define FRE
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
const int maxn=52+8;
char s[maxn][3];
int lft[maxn],rgt[maxn],ans[maxn];

void init()
{
	F(i,0,52){
		lft[i]=i-1;
		rgt[i]=i+1;
		ans[i]=1;
	}
	lft[0]=0;
	lft[53]=52;
}

bool match(char ch1[],char ch2[])
{
	return ch1[0]==ch2[0] || ch1[1]==ch2[1];
}

void link(int a,int b)
{
	rgt[a]=b;
	lft[b]=a;
}

void solve()
{
	stack<char*> st[maxn];
	st[1].push(s[1]);
	bool vis[maxn];
	F(i,2,52){
		scanf("%s",s[i]);
		st[i].push(s[i]);
	}
	bool move=true;
	while(move){
		move=false;
		int i=1;
		while(i<=52){
			int lf3=lft[lft[lft[i]]],lf=lft[i],rt=rgt[i];
			//debug(i,lf,lf3);
			//debug(st[i].size(),st[lf].size(),st[lf3].size());
			//debug(i,lft[i],rgt[i]);
			if(lf3 && !st[i].empty() && !st[lf3].empty() && match(st[i].top(),st[lf3].top())){
				//debug(st[lf3].top(),st[i].top());
				st[lf3].push(st[i].top());
				st[i].pop();
				//debug(i,st[i].size());
				/*lft[i]=lft[lf3];
				  rgt[i]=rgt[lf3];
				  lft[rgt[lf3]]=i;
				  rgt[lft[lf3]]=i;
				  rgt[lf]=rt;
				  lft[rt]=lf;*/
				ans[lf3]++;
				ans[i]--;
				if(st[i].empty())
					link(lf,rt);
				move=1;
				break;
			}
			else if(lf && !st[i].empty() && !st[lf].empty() && match(st[i].top(),st[lf].top())){
				//debug(st[lf].top(),st[i].top());
				st[lf3].push(st[i].top());
				st[i].pop();
				/*lft[i]=lft[lf];
				  rgt[i]=rgt[lf];
				  lft[rgt[lf]]=i;
				  rgt[lft[lf]]=i;
				  rgt[lf]=rt;
				  lft[rt]=lf;*/
				ans[lf]++;
				ans[i]--;
				if(st[i].empty())
					link(lf,rt);
				move=1;
				break;
			}
			i=rgt[i];
		}
	}
	int sum=0;
	vector<int> tol;
	F(i,0,52){
		//debug(i,lft[i],rgt[i]);
		if (!st[i].empty()){
			sum++;
			tol.pb(st[i].size());
			debug(st[i].top());
		}
	}
	printf("%d piles remaining: ",sum);
	F(i,0,tol.size()-1){
		if(i) printf(" ");	
		printf("%d",tol[i]);
	}
	printf("\n");
}

int main()
{
	FRER;
	//FREW;
	while(scanf("%s",s[1])==1 && s[1][0]!='#'){
		init();
		solve();
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}


