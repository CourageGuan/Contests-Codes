/*想法很简单，统计所有相同y坐标x的平均值，均相等则为左右对称*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月03日 星期六 22时12分21秒
 & File Name: uva1595.cpp
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
#define SET(a,t) memset(a,t,sizeof(a))
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



bool solve(int n)
{
	map<double,double> yx,time;	
	double vy[2000];
	yx.clear();
	time.clear();
	if(n&1)
	{
		F(i,0,n-1)
		{
			double x,y;
			cin>>x>>y;
			vy[i]=y;
			time[y]+=1.0;
			yx[y]+=x;
		}
		sort(vy,vy+n);
		int m=unique(vy,vy+n)-vy;
		F(i,0,m-1)
		{
			yx[vy[i]]/=time[vy[i]];
			if(i && yx[vy[i]]!=yx[vy[i-1]]) return false;
		}
		return true;
	}
	else
	{
		F(i,0,n-1)
		{
			double x,y;
			cin>>x>>y;
			vy[i]=y;
			time[y]++;
			yx[y]+=x;
		}
		sort(vy,vy+n);
		int m=unique(vy,vy+n)-vy;
		F(i,0,m-1)
		{
			yx[vy[i]]=yx[vy[i]]/time[vy[i]];
			if(i && yx[vy[i]]!=yx[vy[i-1]]) return false;
		}
		return true;
	}

}

int main()
{
	FRER;
	//FREW;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		puts((solve(n))?"YES":"NO");
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}







