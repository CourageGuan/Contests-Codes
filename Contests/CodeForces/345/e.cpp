#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<pair<int,int> > a;
int tx[maxn],ty[maxn],X[maxn],Y[maxn],ans[maxn],fa[maxn];
int n,m;

int find(int u)
{
	return u == fa[u]?u:fa[u] = find(fa[u]);
}

int uni(int u,int v)
{
	int t1 = find(u),t2 = find(v);
	if(t1 != t2) fa[t1] = t2;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	int s = n*m;
	for(int i=0;i<s;++i)
	{
		int x;
		scanf("%d",&x);
		a.push_back(make_pair(x,i));
		fa[i] = i;
	}
	sort(a.begin(),a.end());
	int lst = 0;
	for(int i=0;i<s;++i)
	{
		if(i < s-1 && a[i].first == a[i+1].first) continue;
		for(int j=lst;j<=i;++j)
		{
			int r = a[j].second/m,c = a[j].second%m;
			tx[r] = a[j].second;
			ty[c] = a[j].second;
		}
		for(int j=lst;j<=i;++j) 
		{
			int r = a[j].second/m,c = a[j].second%m;
			uni(tx[r],a[j].second);
			uni(ty[c],a[j].second);
		}
		for(int j=lst;j<=i;++j)
		{
			int r = a[j].second/m,c = a[j].second%m;
			int pa = find(a[j].second);
			ans[pa] = max(ans[pa],max(X[r],Y[c])+1);
		}
		for(int j=lst;j<=i;++j)
		{
			int r = a[j].second/m,c = a[j].second%m;
			int pa = find(a[j].second);
			X[r] = max(X[r],ans[pa]);
			Y[c] = max(Y[c],ans[pa]);
		}
		lst = i+1;
	}
	for(int i=0;i<s;++i)
	{
		printf("%d ",ans[find(i)]);
		if((i+1)%m == 0) puts("");
	}
	return 0;
}
