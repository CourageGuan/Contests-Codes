#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 5010;
int n,m,k;
int p[2][maxn],a[100010];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	memset(p,0,sizeof p);
	a[0] = 0;
	for(int i=1;i<=k;++i)
	{
		int op,r;
		scanf("%d%d%d",&op,&r,a+i);
		p[op-1][r-1] = i;
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			printf("%d ",a[max(p[0][i],p[1][j])]);
		puts("");
	}
	return 0;
}
