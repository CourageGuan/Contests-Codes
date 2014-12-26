/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2014年12月25日 星期四 17时16分56秒
 & File Name: uva540.cpp
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

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

/*-----  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux  -----*/

const int N=1005;

queue<int> T,Team[N];
MII PT;	//Peo->Team;
int t;

void init()
{
	PT.clear();
	SETS(T);
	F(i,1,t) SETS(Team[i]);
}

void solve(int kase,int n)
{
	if(kase==1)
		if(Team[PT[n]].empty())
		{
			T.push(PT[n]);
			Team[PT[n]].push(n);
		}else {Team[PT[n]].push(n);}
	else{
		printf("%d\n",Team[T.front()].front());
		Team[T.front()].pop();
		if(Team[T.front()].empty()) T.pop();
	}
}

int main()
{
	//FRER;
	//FREW;
	int _=0;
	while(scanf("%d",&t)==1 && t)
	{
		printf("Scenario #%d\n",++_);
		init();
		F(i,1,t)
		{
			int n;
			scanf("%d",&n);
			while(n--)	
			{
				int p;
				scanf("%d",&p);
				PT[p]=i;
			}
		}
		char ch[10];
		while(scanf("%s",ch)&&ch[0]!='S')
		{
			if(ch[0]=='E')
			{
				int n;
				scanf("%d",&n);
				solve(1,n);
			}else solve(2,0);	//1\2 是标号,0无意义...
		}
		puts("");
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

