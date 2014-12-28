/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2014年12月26日 星期五 23时30分12秒
 & File Name:
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

#define F(i,a,b) for(int i=a;i<=b;i++)
#define Fd(i,a,b) for(int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define SET(a,t) memset(a,t,sizeof(a))
#define SETS(ST) while(!ST.empty()) ST.pop();
#define DEBUG puts("OK")
#define C(a) cout<<"~~"<<a<<"~~"<<endl
#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;}

#define FRER freopen("test","r",stdin)
#define FREW freopen("1","w",stdout)

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

int n,m;
map<pair<string,string>,int> mp;
string ss[10010][15];

void init()
{
	mp.clear();
	F(i,0,10000)
		F(j,0,10) ss[i][j].clear();
}

void solve()
{
	int c1=0,c2=0,r1=0,r2=0;
	bool flag=true;
	F(x,1,m)
	{
		F(i,x+1,m)
		{
			mp.clear();
			F(j,1,n)
			{
				pair<string,string> pp(ss[j][x],ss[j][i]);
				if(mp.count(pp))
				{
					flag=false;
					c1=x;c2=i;r1=mp[pp];r2=j;
					break;
				}else mp[pp]=j;
			}
			if(!flag) break;
		}
		if(!flag) break;
	}
	if(flag) {puts("YES");return;}
	puts("NO");
	printf("%d %d\n",r1,r2);
	printf("%d %d\n",c1,c2);
}


int main()
{
	FRER;
	FREW;
	while(scanf("%d%d",&n,&m)==2)
	{
		getchar();
		init();
		char ch[500];
		int t=0;
		while(scanf("%[^','^\n]%*c",ch)==1)
		{
			ss[t/m+1][t%m+1]=ch;
			if(++t>=n*m) break;
		}
		solve();
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}



