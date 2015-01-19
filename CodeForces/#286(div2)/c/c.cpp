/*BFS,TLE,WA...*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月18日 星期日 22时01分11秒
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

#define DEBUG
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

#define FRE
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

const int maxn=30000+10;
int  gem[maxn];
int ans[maxn];
int n,dis,mx;

set<PII> status;
queue<int> pos;
queue<int> len;

void solve()
{
	SET(ans,0);
	int d=dis;
	pos.push(d);
	pos.push(d);
	pos.push(d);
	len.push(d-1);
	len.push(d);
	len.push(d+1);
	status.insert(mp(d,d-1));
	status.insert(mp(d,d));
	status.insert(mp(d,+1));
	ans[d]+=gem[d];
	int cnt=0;
	while(!pos.empty()){
		int p=pos.front(),l=len.front();
		pos.pop();len.pop();
		int po=p+l;
		if(po>mx) continue;
		//debug(p,l);
		if(po<=mx && l>0){
			ans[po]=max(ans[po],ans[p]+gem[po]);
			if(!status.count(mp(po,l-1))){
				pos.push(po);
				len.push(l-1);
				status.insert(mp(po,l-1));
			}
			if(!status.count(mp(po,l))){
				pos.push(po);
				len.push(l);
				status.insert(mp(po,l));
			}
			if(!status.count(mp(po,l+1))){
				pos.push(po);
				len.push(l+1);
				status.insert(mp(po,l+1));
			}
		}
		//if(cnt++>1000000) break;
	}
	int res=0;
	F(i,dis,mx){
		res=max(res,ans[i]);
	}
	printf("%d\n",res);
}

int main()
{
	//FRER;
	//FREW;
	scanf("%d%d",&n,&dis);
	SET(gem,0);
	F(i,1,n){
		int v;
		scanf("%d",&v);
		mx=v;
		gem[v]++;
	}
	/*F(i,1,100)
		if (gem[i])
			debug(i,gem[i]);*/
	solve();
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}



