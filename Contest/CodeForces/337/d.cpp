#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back

const int maxn = 1e5 + 10;
struct Edge{
	int x,y1,y2,in;
	Edge(int x,int y1,int y2,int in):x(x),y1(y1),y2(y2),in(in) {}
	bool operator<(const Edge& rhs) const{
		return x < rhs.x;
	}
};

struct Node{
	int cnt;
	LL	len;
	Node() { cnt = len = 0; }
} p[maxn<<3];

vector<Edge> save;
vector<int> point;

void pushup(int L,int R,int u)
{
	if(p[u].cnt) p[u].len = point[R+1] - point[L];
	else if(L == R) p[u].len = 0;
	else p[u].len = p[u<<1].len + p[u<<1|1].len;
}

void update(int cL,int cR,int add,int L,int R,int u)
{
	if(cL <= L && R <= cR)
	{
		p[u].cnt += add;
	}
	else
	{
		int m = (L+R)>>1;
		if(m >= cL) update(cL,cR,add,L,m,u<<1);
		if(m < cR) update(cL,cR,add,m+1,R,u<<1|1);
	}
	pushup(L,R,u);
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1 > x2) swap(x1,x2);
		if(y1 > y2) swap(y1,y2);
		++x2; ++y2;
		save.pb(Edge(x1,y1,y2,1));
		save.pb(Edge(x2,y1,y2,-1));
		point.pb(y1);
		point.pb(y2);
	}
	sort(save.begin(),save.end());
	sort(point.begin(),point.end());
	int pn = unique(point.begin(),point.end()) - point.begin();
	LL res = 0;
	for(int i=0;i<save.size() - 1;++i)
	{
		int L = lower_bound(point.begin(),point.begin() + pn,save[i].y1) - point.begin();
		int R = lower_bound(point.begin(),point.begin() + pn,save[i].y2) - point.begin() - 1;
		if(L <= R) update(L,R,save[i].in,0,pn-1,1);
		res += p[1].len*(save[i+1].x - save[i].x);
	}
	printf("%lld\n",res);
	return 0;
}

