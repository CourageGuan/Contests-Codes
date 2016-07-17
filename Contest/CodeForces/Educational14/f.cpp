#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e6 + 1;
int n,m;
int cnt[3*maxn];
LL t[3*maxn],sum[3*maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	int a;
	for(int i=0;i<n;++i) scanf("%d",&a),cnt[a]++;
	for(int i=1;i<maxn*3;++i)
	{
		if(cnt[i] == 0) continue;
		for(int j=1;1LL*i*j<maxn*3;++j)
		{
			t[i*j] += 1LL*cnt[i]*cnt[j];
			if(i == j) t[i*j] -= cnt[i];
		}
	}
	for(int i=1;i<maxn*3;++i)
	{
		sum[i] = sum[i-1] + t[i];
	}
	LL tot = 1LL*n*(n-1);
	cin >> m;
	for(int i=0;i<m;++i)
	{
		int p;
		scanf("%d",&p);
		printf("%lld\n",tot - sum[p-1]);
	}
	return 0;
}
