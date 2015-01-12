/*离散化　算法另外总结　
  大体思想是不考虑y方向上的长度，把所有的x坐标抽出来，去重排序，
  判断每个建筑的南墙的在每个区间的中点(其他点也可以)是否可见*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月02日 星期五 16时56分49秒
 & File Name: uva221.cpp
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
const int maxn=110;

class building{
public:
	int x,y,w,l,h;
	int id;

	bool operator < (const building& b)const {
		return x<b.x || (x==b.x && y<b.y);
	}
} bd[maxn];

int x[maxn*2];
int n;

bool cover(int i,int mx)
{
	return mx>=bd[i].x && mx<=(bd[i].x+bd[i].w);
}

bool isvis(int i,int mx)
{
	if(!cover(i,mx)) return false;
	F(j,0,n-1)
		if(cover(j,mx) && bd[j].h>=bd[i].h && bd[j].y<bd[i].y) return false;
	return true;
}

int main()
{
	FRER;
	FREW;
	int kase=0;
	while(cin>>n && n)
	{
		F(i,0,n-1)
		{
			bd[i].id=i+1;
			scanf("%d%d%d%d%d",&bd[i].x,&bd[i].y,&bd[i].w,&bd[i].l,&bd[i].h);
			x[2*i]=bd[i].x;x[2*i+1]=bd[i].x+bd[i].w;
			/*maxx=max(maxx,bd[i]._x);
			minx=min(minx,bd[i].x);
			maxy=max(maxy,bd[i]._y);
			miny=min(miny,bd[i].y);
			F(j,bd[i].x,bd[i]._x)
				F(k,bd[i].y,bd[i]._y)
					pic[j][k]=bd[i].h;*/
		}
		sort(x,x+2*n);
		int m=unique(x,x+2*n)-x;
		sort(bd,bd+n);
		F(i,0,n) debug(i,bd[i].x,bd[i].y);
		if(kase++) puts("");	
		printf("For map #%d, the visible buildings are numbered as follows:\n",kase);
		printf("%d",bd[0].id);
		F(i,1,n-1){
			bool flag=false;
			F(j,0,m-2)
				if(isvis(i,(x[j]+x[j+1])/2)){flag=true;break;}
			if(flag) printf(" %d",bd[i].id);
		}

		//PM(pic,maxx,maxy);
		/*F(j,minx,maxx){
			int high=0,t=1;
			F(i,miny,maxy){
				if(high==pic[j][i] && high!=0 && t){
					pic[j][i]-=1;
					t--;
					continue;
				}
				high=max(high,pic[j][i]);
				pic[j][i]==high;
			}
		}
		//PM(pic,maxx,maxy);
		F(i,0,n-1)
			F(j,bd[i].x,bd[i]._x)
				if(pic[j][bd[i].y]<bd[i].h){
					bd[i].is_visible=true;
					break;
				}
		printf("For map #%d, the visible buildings are numbered as follows:\n",kase++);
		int t=0;
		F(i,1,n)
			if(bd[i].is_visible)
				if(t) printf(" %d",bd[i].id);
				else{
					printf("%d",bd[i].id);
					t++;
				}
	 	printf("\n\n");*/
	 	printf("\n");
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

