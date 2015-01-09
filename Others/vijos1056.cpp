/*离散化，记录所有的x坐标,y坐标
　分别对x,y排序,然后记录相邻两个x和相邻两个y围成的区间面积
　即将整个图分为(2*n-1)²个区间，然后看这些区间是否在矩形内
　若在则标记flag,最后将在矩形内的区间面积相加*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月03日 星期六 11时14分52秒
 & File Name: vijos1056.cpp
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
#else
	#define debug(args...)
	#define OK
	#define C(a)
	#define PM(a,x,y)
#endif

struct debugger{
	template<typename T> debugger& operator , (const T& v){
		cerr<<v<<" ";
		return *this;
	}
} dbg;

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

struct rec{
	long long x,y,xx,yy;
	/*bool operator <(const rec& b) const{
		return x<b.x || (x==b.x) && y<b.y;
	}*/
} p[110];

long long n,pic[210][210],xx[210],yy[210];
bool flag[210][210];

bool in(int x,int xx,int y,int yy)
{
	F(i,0,n-1)
		if(x>=p[i].x && y>=p[i].y && xx<=p[i].xx && yy<=p[i].yy) return true;
	return false;
}

int main()
{
	FRER;
	//FREW;
	SET(p,0);
	SET(pic,0);
	SET(flag,false);
	cin>>n;
	F(i,0,n-1)
	{
		cin>>p[i].x>>p[i].y>>p[i].xx>>p[i].yy;
		xx[2*i]=p[i].x;
		xx[2*i+1]=p[i].xx;	
		yy[2*i]=p[i].y;
		yy[2*i+1]=p[i].yy;
	}
	sort(xx,xx+2*n);
	sort(yy,yy+2*n);
	F(i,0,2*n-2)
		F(j,0,2*n-2){
			pic[i][j]=(xx[j+1]-xx[j])*(yy[i+1]-yy[i]);
			if(in(xx[j],xx[j+1],yy[i],yy[i+1])) flag[i][j]=true;
		}
	PM(flag,2*n-2,2*n-2);
	PM(pic,2*n-2,2*n-2);
	long long ans=0;
	F(i,0,2*n-2)
		F(j,0,2*n-2)
			if(flag[i][j]) ans+=pic[i][j];
	cout<<ans<<endl;
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

