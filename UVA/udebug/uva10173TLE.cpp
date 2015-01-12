/*TLE,涉及计算几何里的凸包算法，自己的O(n²)超时，等掌握了更快的算法来优化*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月04日 星期日 14时24分40秒
 & File Name: uva10173.cpp
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>

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

const int maxn=1234;
double dx[maxn],dy[maxn];

void init()
{
	SET(dx,0.0);
	SET(dy,0.0);
}

double dis(double a,double b,double c,double x,double y)
{
	if(a==0) return y-c;
	if(b==0) return x-c;
	double d=a*x+b*y+c;
	if(fabs(d)<EPS) return 0.0;
	return d/sqrt(a*a+b*b);
}

double solve(int n)
{
	double ans=inf*1.0;
	F(i,1,n-1){
		F(j,i+1,n){
			double maxx=0.0,minx=0.0,maxy=0.0,miny=0.0;
			double a,b,c;
			a=dy[i]-dy[j];	//a=y1-y2
			b=dx[j]-dx[i];	//b=x2-x1
			c=-(a*dx[i]+b*dy[i]);	//c=-ax1-by1;
			if(a==0)
			{
				b=1.0;
				c=dy[i];
			}
			if(b==0)
			{
				a=1.0;
				c=dx[j];
			}
			double A,B,C,X=(dx[i]+dx[j])/2,Y=(dy[i]+dy[j])/2,K=(dx[j]-dx[i])/(dy[i]-dy[j]);
			A=K;
			B=-1;
			C=Y-K*X;
			if(dy[j]-dy[i]==0)
			{
				A=1.0;
				B=0;
				C=X;
			}
			if(K==0)
			{
				A=0;
				B=1.0;
				C=Y;
			}
			F(k,1,n){
				//debug(i,j,k,dis(a,b,c,dx[k],dy[k]));
				if(dis(a,b,c,dx[k],dy[k])>0)
					maxx=max(maxx,dis(a,b,c,dx[k],dy[k]));
				else
					minx=min(minx,dis(a,b,c,dx[k],dy[k]));
				//debug(i,j,k,dis(A,B,C,dx[k],dy[k]));
				if(dis(A,B,C,dx[k],dy[k])>0)
					maxy=max(maxy,dis(A,B,C,dx[k],dy[k]));
				else
					miny=min(miny,dis(A,B,C,dx[k],dy[k]));
			}
			ans=min(ans,(maxx-minx)*(maxy-miny));
		}
	}
	return ans;
}

int main()
{
	FRER;
	//FREW;
	int n;
	while(scanf("%d",&n)==1 && n)
	{
		init();
		F(i,1,n)
			scanf("%lf%lf",&dx[i],&dy[i]);
		//F(i,1,n)
		//	debug(i,dx[i],dy[i]);
		double ans=solve(n);
		printf("%.4lf\n",ans);
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

