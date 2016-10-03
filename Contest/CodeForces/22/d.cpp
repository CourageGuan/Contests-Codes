#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1010;
int vis[maxn];
struct P{
	int l,r,id;
	bool operator<(const P& rhs) const {
		return r < rhs.r;
	}
} p[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	F(i,0,n-1)
	{ 
		scanf("%d %d",&p[i].l,&p[i].r),p[i].id = i;
		if(p[i].l > p[i].r) swap(p[i].l,p[i].r);
	}
	sort(p,p+n);
	vector<int> ans;
	F(i,0,n-1)
	{
		if(vis[p[i].id]) continue;
		ans.push_back(p[i].r);
		F(j,i+1,n-1) if(p[j].l <= p[i].r && p[j].r >= p[i].r) vis[p[j].id] = 1;
	}
	printf("%d\n",int(ans.size()));
	for(auto it:ans) printf("%d ",it);
	return 0;
}
