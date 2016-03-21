/*题意很简单，按照一颗树的dfs序列和bfs序列构造，写出每个节点的子节点
  方法是用bfs序列确定bfs序列中某个节点的子节点，dfs中某个节点的子节点
  总在这个节点之后，然后对比其子节点是否在这个节点的下一层，
  但是有些细节需要注意，因为都是按照节点编号升序遍历的，因此在bfs序列
  中一旦降序，则说明该层已遍历结束*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月17日 星期六 20时49分40秒
 & File Name: uva10410.cpp
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

const int maxn=1234;
int bfs[maxn],dfs[maxn],pos[maxn];


void solve(int n)
{
	vector<int> ans[maxn];
	bool vis[maxn];
	SET(vis,0);
	int cnt=0;
	/*F(i,2,n){
		if(!vis[dfs[i]]){
			debug(dfs[i]);
			cnt++;
			F(k,i,n){
				if(bfs[k]){
					if(vis[bfs[k]]) continue;
					if(bfs[k]==dfs[i+1]) break;
					layer[cnt].insert(bfs[k]);
					ly[bfs[k]]=cnt;
					vis[bfs[k]]=1;
					//debug(cnt,bfs[k]);
				}
			}
		}else cnt--;
	}*/
	int layer[maxn];
	SET(layer,0);
	layer[bfs[1]]=1;
	F(i,1,n-1){		
		int t=bfs[i];
		int l=1,r=i+1;
		while(dfs[l]!=t) l++;
		while(vis[bfs[r]]) r++;
		l++;
		while(l<=n){
			if(layer[dfs[l]]==layer[t]) break;
			if(dfs[l]==bfs[r]){
				ans[t].pb(dfs[l]);
				layer[dfs[l]]=layer[t]+1;
				vis[dfs[l]]=1;
				r++;
				if(bfs[r]<bfs[r-1]) break;
			}
			l++;
		}
	}
	F(i,1,n){
		printf("%d:",i);
		if(ans[i].size()){
			F(j,0,ans[i].size()-1)
				printf(" %d",ans[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	FRER;
	//FREW;
	int n;
	while(scanf("%d",&n)==1){
		F(i,1,n) scanf("%d",&bfs[i]);
		F(i,1,n) scanf("%d",&dfs[i]);
		dfs[0]=bfs[0]=0;
		solve(n);
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}


