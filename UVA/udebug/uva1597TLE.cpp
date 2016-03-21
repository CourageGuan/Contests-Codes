/*输入输出太多，必须用map实现题目描述的倒排索引，否则超时*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月06日 星期二 22时25分30秒
 & File Name: uva1597.cpp
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
#define md "----------"
#define mk "=========="
#define sorry "Sorry, I found nothing."

vector<string> art[123];
int n,m;

void init()
{
	F(i,0,n)
		art[i].clear();
}

string lower(string s)
{
	string ss=s;
	transform(ALL(ss),ss.begin(),::tolower);
	return ss;
}

void deal(string s)
{
	int pr=0;
	F(i,1,n){
		int m=art[i].size()-1,flag=0;
		F(j,0,m){
			string low=lower(art[i][j]);
			if(low.find(s)!=-1){
				flag++;
				if(flag==1){
					flag++;
					pr++;
				}
				if(pr && pr!=1) puts(md);
				cout<<art[i][j]<<endl;
			}
		}
	}
	if (!pr) puts(sorry);
	puts(mk);
}

void dealo(string s1,string s2)
{
	int pr=0;
	F(i,1,n){
		int m=art[i].size()-1,flag=0;
		F(j,0,m){
			string low=lower(art[i][j]);
			if(low.find(s1)!=-1 || low.find(s2)!=-1){
				flag++;
				if(flag==1){
					flag++;
					pr++;
				}
				if(pr && pr!=1) puts(md);
				cout<<art[i][j]<<endl;
			}
		}
	}
	if(!pr) puts(sorry);
	puts(mk);
}

void deala(string s1,string s2)
{
	int pr=0;
	F(i,1,n){
		int m=art[i].size()-1,flag=0;
		bool flag1=false,flag2=false;
		F(j,0,m){
			string low=lower(art[i][j]);
			if(low.find(s1)!=-1)
				flag1=true;
			if(low.find(s2)!=-1)
				flag2=true;
			if(flag1 && flag2) break;
		}
		if(!(flag1 && flag2)) continue;
		F(j,0,m){
			string low=lower(art[i][j]);
			if(low.find(s1)!=-1 || low.find(s2)!=-1){
				flag++;
				if(flag==1){
					flag++;
					pr++;
				}
				if(pr && pr!=1) puts(md);
				cout<<art[i][j]<<endl;
			}
		}
	}
	if(!pr) puts(sorry);
	puts(mk);
}

void dealn(string s)
{
	int pr=0;
	F(i,1,n){
		int m=art[i].size()-1,f=0;
		bool flag=true;
		F(j,0,m){
			string low=lower(art[i][j]);
			if(low.find(s)!=-1){
				flag=false;
				break;
			}
		}
		if(!flag) continue;
		F(j,0,m){
			f++;
			if(f==1){
				f++;
				pr++;
			}
			if(pr && pr!=1 && f==2) puts(md);
			cout<<art[i][j]<<endl;
		}
	}
	if(!pr) puts(sorry);
	puts(mk);
}

void solve()
{
	scanf("%d",&n);
	getchar();
	int i=1;
	while(i<=n)
	{
		string s;
		getline(cin,s);
		if(s[0]=='*'){
			i++;
			continue;
		}
		art[i].pb(s);
	}
	scanf("%d",&m);
	getchar();
	while(m--)
	{
		string s;
		getline(cin,s);
		if(s.find("AND")!=-1){
			string s1=s.substr(0,s.find('A')-1),
				   s2=s.substr(s.find('D')+2,s.size()-s.find('D')-2);
			deala(s1,s2);
			continue;
		}
		if(s.find("OR")!=-1){
			string s1=s.substr(0,s.find('O')-1),
				   s2=s.substr(s.find('R')+2,s.size()-s.find('R')-2);
			dealo(s1,s2);
			continue;
		}
		if(s.find("NOT")!=-1){
			s.erase(0,4);
			dealn(s);
			continue;
		}
		deal(s);
	}
}

int main()
{
	FRER;
	FREW;
	init();
	solve();
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}



