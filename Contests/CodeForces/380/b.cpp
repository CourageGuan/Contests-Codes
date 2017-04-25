#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1010;
int n,m,t;
int mx[2][maxn],mn[2][maxn],pic[maxn][maxn];

void solve()
{
	scanf("%d %d",&n,&m);
	memset(mn,0x3f,sizeof mn);
	F(i,1,n) F(j,1,m)
	{
		int t;
		scanf("%d",&t);
		if(t)
		{
			mx[0][i] = max(mx[0][i],j);
			mx[1][j] = max(mx[1][j],i);

			mn[0][i] = min(mn[0][i],j);
			mn[1][j] = min(mn[1][j],i);
		}
		pic[i][j] = t;
	}
	int ans = 0;
	F(i,1,n) F(j,1,m)
	{
		if(pic[i][j]) continue;
		if(i > mn[1][j]) ++ans;
		if(i < mx[1][j]) ++ans;
		if(j > mn[0][i]) ++ans;
		if(j < mx[0][i]) ++ans;
	}
	printf("%d\n",ans);
}

int main()
{
//	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
