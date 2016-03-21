/*又一道链表题，果然很难操作，不确定因素太多*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月08日 星期四 10时26分21秒
 & File Name: uva12657.cpp
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

int _right[123456],_left[123456];
int m,n;
bool ltor;

void link(int x,int y)
{
	_left[y]=x;_right[x]=y;
}

void init()
{
	SET(_right,0);
	SET(_left,0);
	_right[0]=1;
	_left[n+1]=n;
	F(i,1,n){
		_right[i]=i+1;
		_left[i]=i-1;
	}
	ltor=true;
}


void linkl(int x,int y)
{
	if(_left[y]==x) return;
	if(_right[y]==x)
		_right[y]=_right[x];
	_right[_left[x]]=_right[x];
	_left[_right[x]]=_left[x];
	_right[_left[y]]=x;
	_left[x]=_left[y];
	_left[y]=x;
	_right[x]=y;
}

void linkr(int x,int y)
{
	if(_right[y]==x) return;
	if(_left[y]==x)
		_left[y]=_left[x];
	_right[_left[x]]=_right[x];
	_left[_right[x]]=_left[x];
	_left[_right[y]]=x;
	_right[x]=_right[y];
	_right[y]=x;
	_left[x]=y;
}

void _swap(int x,int y)
{
	int lx=_left[x],rx=_right[x],
	    ly=_left[y],ry=_right[y];
	if(lx==y){
		_left[y]=ry;
		_right[y]=rx;
		_left[x]=ly;
		_right[x]=lx;
		_right[ly]=x;
		_left[rx]=y;
		return;
	}
	if(ly==x){
		_left[y]=lx;
		_right[y]=ly;
		_left[x]=rx;
		_right[x]=ry;
		_right[lx]=y;
		_left[ry]=x;
		return;
	}
	link(ly,x);
	link(x,ry);
	link(lx,y);
	link(y,rx);
}

void solve(int op,int x,int y)
{
	switch(op)
	{
		case 4:ltor=!ltor;return;
		case 1:
			   if(ltor) linkl(x,y);
			   else linkr(x,y);
			   break;
		case 2:
			   if(ltor) linkr(x,y);
			   else linkl(x,y);
			   break;
		case 3:_swap(x,y);break;
	}
}

long long sum(){
	long long ans=0;
	//F(i,0,n+1) debug(i,_left[i],_right[i]);
	if(ltor)
		for(int i=_right[0];(i!=n+1) && (i!=0);i=_right[_right[i]]) {
			ans+=i;
		}
	else
		for(int i=_left[n+1];i!=0;i=_left[_left[i]]) ans+=i;
	return ans;
}


int main()
{
	FRER;
	//FREW;
	int kase=1;
	while(scanf("%d%d",&n,&m)==2){
		init();
		while(m--){
			int op;
			scanf("%d",&op);
			if(op!=4){
				int x,y;
				scanf("%d %d",&x,&y);
				solve(op,x,y);
			}
			else solve(op,0,0);
		}
		printf("Case %d: %lld\n",kase++,sum());
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

