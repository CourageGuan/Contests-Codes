/*用二叉树的后序遍历和中序遍历递归构造，同时记录每个node到根的距离*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月09日 星期五 15时09分31秒
 & File Name: uva548.cpp
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sstream>

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
const int maxn=12345;
int in_order[maxn],post_order[maxn];
int ans,minv,n;

struct Node{
	int v;
	Node *lch,*rch;
} node[maxn],*root;

queue<Node*> freenodes;		//free list => memory pool

void init()
{
	SETS(freenodes);
	for(int i=0;i<=n;++i)
		freenodes.push(&node[i]);
}

Node *newnode()
{
	Node* p=freenodes.front();
	p->lch=p->rch=NULL;
	freenodes.pop();
	return p;
}

void delnode(Node* p)
{
	freenodes.push(p);
}

void clear_tree(Node* p)
{
	if(p==NULL) return;
	clear_tree(p->lch);
	clear_tree(p->rch);
	delnode(p);
}

Node* build(int dis,int l1,int r1,int l2,int r2)
{
	if(l1>r1) return NULL;
	Node* p=newnode();
	p->v=post_order[r2];
	int cn=l1,cnt;
	while(in_order[cn]!=p->v) cn++;
	cnt=cn-l1;
	int diss=dis+p->v;
	p->lch=build(diss,l1,cn-1,l2,l2+cnt-1);
	p->rch=build(diss,cn+1,r1,l2+cnt,r2-1);
	/*if(v1){
		p->lch=newnode();
		p->lch->v=v1;
		p->lch->dis=p->v;
	}
	if(v2){
		p->rch=newnode();
		p->rch->v=v2;
		p->rch->dis=p->v;
	}*/
	if(!p->lch && !p->rch)
		if (diss<ans || (diss==ans && p->v<minv)){
			minv=p->v;
			ans=diss;
		}
	return p;
}


int main()
{
	FRER;
	//FREW;
	string s1,s2;
	while(getline(cin,s1)){
		getline(cin,s2);
		stringstream s(s1),ss(s2);
		int x;
		n=0;
		while(s>>x) in_order[n++]=x;
		n=0;
		while(ss>>x) post_order[n++]=x;
		ans=inf;minv=inf;
		init();
		root=newnode();
		root=build(0,0,n-1,0,n-1);
		clear_tree(root);
		printf("%d\n",minv);
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}


