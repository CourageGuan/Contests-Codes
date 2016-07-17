#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e6;
vector<int> v[maxn];
int it[maxn];
int n,m;
int p[maxn],f[maxn];

int find(int x)
{
	return f[x] == x?x:f[x] = find(f[x]);
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",p+i);

	for(int i=1;i<=n;++i) f[i] = i;

	for(int i=0;i<m;++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		int u = find(a),v = find(b);
		f[u] = v;
	}

	for(int i=1;i<=n;++i)
	{
		v[find(i)].push_back(p[i]);
	}


	for(int i=1;i<=n;++i)
	{
		sort(v[i].begin(),v[i].end(),greater<int>());
	}

	for(int i=1;i<=n;++i)
	{
		printf("%d ", v[find(i)][it[find(i)]++] );
	}
	puts("");
	return 0;
}


