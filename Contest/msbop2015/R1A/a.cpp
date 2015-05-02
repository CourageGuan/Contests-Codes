/*
 & Created Time:  Sat 25 Apr 2015 03:38:31 PM CST
 & File Name: a.cpp
 & Author: NoBystander
*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <utility>
using namespace std;


#define LEN(n) (int)log10(n)+1
#define REP(i,n) for(int i=0;i<n;++i)
#define F(i,a,b) for(int i=a;(i)<b;++i)
#define Fd(i,b,a) for(int i=b-1;i>=a;--i)
#define EACH(i,a) for(__typeof((a).begin()) i=a.begin(); i!=a.end(); ++i)

#define FILL(a,t) memset((a),(t),sizeof(a))
#define CLEAR(ST) while(!ST.empty()) ST.pop();
#define all(a) a.begin(),a.end()
#define sz(a) ((int)(a).size())
#define lowbd(a,x) lower_bound(all(a),x) - a.begin()
#define upbd(a,x) upper_bound(all(a),x) - a.begin()
#define pb push_back
#define mp(A,B) make_pair(A,B)
#define fi first
#define se second

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
typedef long double LDB;
typedef vector<int> VI;
typedef map<string,int> MSI;
typedef map<int,int> MII;
typedef pair<int,int> PII;
#define priority_queue PQ


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

const int INF = 0x3f3f3f3f;
const LL  LINF = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-9;
const DB PI = acos(-1.0);

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int mv[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

LL nextInt(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	LL res=0;
	while(isdigit(ch)){
		res=res*10+ch-48;
		ch=getchar();
	}
	return res;
}

void write(LL x){
	if(x>9) write(x/10);
	putchar(x%10+48);
}

/*-----  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux  -----*/

void init()
{

}

void solve()
{

}

const int maxn = 100010;
int n;
vector<int> G[maxn];
int col[maxn];


int Que(int u,int fa)
{
    int cnt = 0;
    for(int i = 0;i < G[u].size();++i)
    {
        int v = G[u][i];
        if(v == fa) continue;
        cnt += Que(v,u) + (col[u] == col[v] ? -1:0);
    }
    cnt++;
    return cnt;
}

int main()
{
    int T,kase=0;
    scanf("%d",&T);
	while(T--)
    {
        scanf("%d",&n);
        memset(col,0,sizeof(col));
        for(int i = 1;i <= n;++i)
            G[i].clear();
        for(int i = 0;i < n-1;++i)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].pb(b);
            G[b].pb(a);
        }
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",++kase);
        while(q--)
        {
            int t;
            scanf("%d",&t);
            if(t == 1)
                printf("%d\n",Que(1,-1));
            else
            {
                int x,c;
                scanf("%d %d",&x,&c);
                col[x] = c;
            }
        }
    }
    return 0;
}

