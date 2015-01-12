/*题目乍一看很难，但是观察一下六个字符最大的区别----洞
  于是种子填充，统计每个象形文字的洞的个数*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月10日 星期六 17时18分36秒
 & File Name: uva1103.cpp
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
#define F(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define Fd(i,a,b) for(int (i)=(a);(i)>=(b);--i
#define Fit(i,a) for(__typeof((a).begin()) i=a.begin(); i!=(a).end(); ++i)
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
const int maxn=1234;
const int base[16][4]={{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},
	{0,1,1,1},{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};

int pic[maxn][maxn];
bool have_ar[maxn][maxn];
int cnt,m,n;
string s;

void init()
{
	SET(pic,0);
	SET(have_ar,0);
	s.clear();
}

bool dfs(int x,int y,int c)
{
	bool flag=true;
	if(x<1 || y<0 || x>n || y>4*m-1) return false;
	have_ar[x][y]=1;
	if(c==1){
		F(i,0,3){
			int a=x+mv4[i][0],b=y+mv4[i][1];
			if(!have_ar[a][b] && pic[a][b]==1) dfs(a,b,1);
			if(!have_ar[a][b] && pic[a][b]==0) if(dfs(a,b,0)) cnt++;
			}
		}
	else 
		F(i,0,3){
			int a=x+mv4[i][0],b=y+mv4[i][1];
			if(!have_ar[a][b] && pic[a][b]==0) 
				if (!dfs(a,b,0)) flag=false;
		}
	return flag;
}

int main()
{
	FRER;
	//FREW;
	int kase=1;
	while(cin>>n>>m && n){
		getchar();
		init();
		F(i,1,n){
			F(j,0,m-1){
				char ch=getchar();
				int l=(ch>96)?(ch-'a'+10):ch-'0';
				debug(l);
				F(k,0,3)		
					pic[i][j*4+k]=base[l][k];
			}
			getchar();
		}
		PM(pic,n,4*m-1);
		F(i,1,n)
			F(j,0,4*m-1)
			if(!have_ar[i][j] && pic[i][j]){
				cnt=0;
				dfs(i,j,pic[i][j]);
				switch(cnt){
					case 0:s+="W";break;
					case 1:s+="A";break;
					case 2:s+="K";break;
					case 3:s+="J";break;
					case 4:s+="S";break;
					case 5:s+="D";break;
				}
			}
		sort(ALL(s));
		cout<<"Case "<<kase++<<": "<<s<<endl;
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

