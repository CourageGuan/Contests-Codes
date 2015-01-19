/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月18日 星期日 19时49分36秒
 & File Name: c.cpp
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

const int maxn=123456;
int nodes[maxn],val[maxn];
bool vis[maxn];
long long ans;
int c,n;

vector<int> tree[maxn];

void dfs(int beg,int end,int mi,int eq,int mx,int ma)
{
	if(vis[end]) return;
	vis[end]=1;
	if(mi+eq+mx>=3 && beg<end){
		if(mx>1) return;
		if(mi && eq && mx){ans++;
		debug(beg,end);
		}
	}
	F(j,0,tree[end].size()-1){
		int t=tree[end][j];
		if(!val[t])
			dfs(beg,t,mi,eq+1,mx,ma);
		if(val[t]>0) 
			if(nodes[t]==ma)
				dfs(beg,t,mi,eq,mx,ma);
			else
				dfs(beg,t,mi,eq,mx+1,nodes[t]);
		if(val[t]<0) 
			dfs(beg,t,mi+1,eq,mx,ma);
	}
}

void solve()
{
	ans=0;
	F(i,1,n-2){
		SET(vis,0);
		if(!val[i])
			dfs(i,i,0,1,0,0);
		if(val[i]>0) 
			dfs(i,i,0,0,1,nodes[i]);
		if(val[i]<0) 
			dfs(i,i,1,0,0,0);
	}
	printf("%d\n",ans);
}

int main()
{
	FRER;
	//FREW;
	scanf("%d%d",&n,&c);
	F(i,1,n){
		scanf("%d",&nodes[i]);
		if(nodes[i]==c) val[i]=0;
		if(nodes[i]<c) val[i]=-1;
		if(nodes[i]>c) val[i]=1;
	}
	F(i,1,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		tree[u].pb(v);
		tree[v].pb(u);
	}
	solve();
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}



