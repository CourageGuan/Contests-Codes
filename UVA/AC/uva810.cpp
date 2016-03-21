/*BFS,手写骰子状态...记录路径算是自己想的一种方法*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月21日 星期三 17时17分28秒
 & File Name: uva810.cpp
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
#define pb push
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

#define FRE
#ifdef FRE
	#define FRER freopen("test","r",stdin)
	#define FREW freopen("1","w",stdout)
#else
	#define FRER
	#define FREW
#endif

const int mv4[4][2] = {{1,0}, {-1,0},{0,1}, {0,-1}};
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

const int maxn=10+5;
const int sz[7]={0,6,5,4,3,2,1};
int r,c,r1,c1,d1,d2; 
bool yes;
int pic[maxn][maxn],vis[maxn][maxn][7][7];
vector<PII> ans;
MII fa;

bool inside(int x,int y)
{
	return x>0 && y>0 && x<=r && y<=c;
}

bool match(int x,int y,int d1,int d2)
{
	if(pic[x][y]==d1) return true;
	if(pic[x][y]==-1) return true;
	return false;
}

int hut(int d1,int d2)		//记得以后随身带骰子...
{
	if (d1==1)
		switch(d2){
			case 2:return 3;
			case 3:return 5;
			case 4:return 2;
			case 5:return 4;
		}
	if (d1==2)
		switch(d2){
			case 1:return 4;
			case 3:return 1;
			case 4:return 6;
			case 6:return 3;
		}
	if (d1==3)
		switch(d2){
			case 1:return 2;
			case 2:return 6;
			case 5:return 1;
			case 6:return 5;
		}
	if (d1==4)
		switch(d2){
			case 1:return 5;
			case 2:return 1;
			case 5:return 6;
			case 6:return 2;
		}
	if (d1==5)
		switch(d2){
			case 1:return 3;
			case 3:return 6;
			case 4:return 1;
			case 6:return 4;
		}
	if (d1==6)
		switch(d2){
			case 2:return 4;
			case 3:return 2;
			case 4:return 5;
			case 5:return 3;
		}
}


int bfs(int x0,int y0,int dd,int ddd)
{
	ans.clear();
	fa.clear();
	SET(vis,0);
	queue<PII> q,d;
	q.pb(mp(x0,y0));	
	d.pb(mp(dd,ddd));	
	ans.push_back(mp(x0,y0));
	int pos=0;
	while(!q.empty()){
		int x=q.front().fi,y=q.front().se;q.pop();
		int d1=d.front().fi,d2=d.front().se;d.pop();
		//debug(x,y,d1,d2); 
		if(x==x0 && y==y0 && yes) return true;
		yes=1;
		F(t,0,3){
			int i=x+mv4[t][0],j=y+mv4[t][1];
			//if(dic==(t&1)?t-1:t+1) continue;
			//debug(i,j,d1,d2,t);
			if(inside(i,j) && pic[i][j] && match(i,j,d1,d2)){
				//debug(i,j,d1,d2,t);
				//debug(pic[i][j],p1,p2,t);
				int p1=d1,p2=d2;
				int temp;
				switch(t){
					case 0:temp=p1;p1=sz[p2];p2=temp;break;
					case 1:temp=p2;p2=sz[p1];p1=temp;break;
					case 2:p1=sz[hut(p1,p2)];break;
					case 3:p1=hut(p1,p2);break;
				}
				//debug(i,j,p1,p2,pos);
				if(!vis[i][j][p1][p2]){
					vis[i][j][p1][p2]=1;
					debug(i,j,p1,p2,pos);
					q.pb(mp(i,j));
					d.pb(mp(p1,p2));
					ans.push_back(mp(i,j));		//记录每个节点...
					fa[ans.size()-1]=pos;
					if(i==x0 && j==y0 && yes) return true;
				}
			}
		}
		pos++;	//扩展父节点位置(ans[]中)
	}
	return 0;
}

bool solve()
{
	SET(pic,0);
	cin>>r>>c>>r1>>c1>>d1>>d2;
	F(i,1,r)
		F(j,1,c)
			scanf("%d",&pic[i][j]);
	bool flag=false;
	yes=0;
	if(bfs(r1,c1,d1,d2)) flag=true;
	if(!flag) return false;
	vector<PII> an;
	//F(i,0,ans.size()-1) debug(i,ans[i].fi,ans[i].se,fa[i]);
	for(int i=ans.size()-1;i;i=fa[i]) an.push_back(ans[i]);
	an.push_back(mp(r1,c1));
	int cnt=0;
	Fd(i,an.size()-1,0){
		if(!cnt) printf("\n  ");
		if(i!=0) printf("(%d,%d),",an[i].fi,an[i].se);
		else printf("(%d,%d)",an[i].fi,an[i].se);
		cnt++;
		cnt%=9;
	}
	puts("");
	return true;
}

int main()
{
	//FRER;
	//FREW;
	string name;
	while(cin>>name && name!="END"){
		cout<<name;
		if(!solve())
			puts("\n  No Solution Possible");
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}



