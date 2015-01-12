/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2014年12月30日 星期二 23时22分18秒
 & File Name: T2.cpp
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

double ROUNDF(double x,int n){
	double t1,t2=modf(x,&t1);
	double t3=pow(10,n);
	long t4=long(t2*t3+0.5);
	x=t1+t4/t3;
	return x;
}

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

/*-----  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux  -----*/

int n,p[320],pp[320];
bool flag[320][320],b[320];
set<int> nu,wp;

void dfs(int i)
{
	nu.insert(i);
	wp.insert(p[i]);
	b[i]=0;
	F(j,1,n){
		if(i==j) continue;
		if(flag[j][i] && b[j]) dfs(j);
	}
}

int main()
{
	//FRER;
	//FREW;
	SET(p,0);
	SET(flag,0);
	SET(b,1);
	scanf("%d",&n);
	F(i,1,n){
	   	scanf("%d",&p[i]);
	}
	getchar();
	F(i,1,n){
		F(j,1,n){
			char c;
			scanf("%c",&c);
			flag[i][j]=(c=='1')?1:0;
		}
		getchar();
	}
	F(i,1,n){
		nu.clear();
		wp.clear();
		if(!b[i]) continue;
		dfs(i);
		set<int>::iterator it1,it2;
		it1=nu.begin();
		it2=wp.begin();
		while(it1!=nu.end() && it2!=wp.end()){
			p[*it1]=*it2;
			it1++;it2++;
		}	
	}
	F(i,1,n-1) printf("%d ",p[i]);
	printf("%d\n",p[n]);
    return 0;
}





