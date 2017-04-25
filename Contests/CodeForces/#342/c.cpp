#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 510;
int a[maxn][maxn],n,k;

void solve()
{
	--k;
	int cur = n*n;
	for(int i=0;i<n;++i)
		for(int j=n-1;j>=k;--j)
			a[i][j] = cur--;
	for(int i=0;i<n;++i)
		for(int j=k-1;j>=0;--j)
			a[i][j] = cur--;
	LL res = 0;
	for(int i=0;i<n;++i) res += a[i][k];
	printf("%lld\n",res);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j) printf("%d%c",a[i][j],j==n-1?'\n':' ');
}	

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);	
	solve();
	return 0;
}
