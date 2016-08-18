#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define mp make_pair

const int maxn = 1e5 + 7;
const int LOG = 18;
int n;
int pos[maxn][LOG],mx[maxn][LOG],p[maxn];
LL d[maxn];

pair<int,int> rmq(int L,int R)
{
	int t = p[R-L+1];
	return max(mp(mx[L][t],pos[L][t]),(mp(mx[R-(1<<t)+1][t],pos[R-(1<<t)+1][t]))); 
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	p[0] = -1;
	F(i,1,n-1) scanf("%d",&mx[i][0]),pos[i][0] = i,p[i] = p[i>>1]+1;
	mx[n][0] = pos[n][0] = n;
	for(int i=1;(1<<i) <= n;++i)
	{
		for(int j=1;j+(1<<(i-1)) <= n;++j)
		{
			if(mx[j][i-1] > mx[j+(1<<(i-1))][i-1])
			{
				mx[j][i] = mx[j][i-1];
				pos[j][i] = pos[j][i-1];
			}
			else
			{
				mx[j][i] = mx[j+(1<<(i-1))][i-1];
				pos[j][i] = pos[j+(1<<(i-1))][i-1];
			}
		}
	}
	LL ans = 0;
	d[n] = 0;
	for(int i=n-1;i>=1;--i)
	{
		pair<int,int> pr = rmq(i+1,mx[i][0]);
//		printf("%d\n",pr.second);
		d[i] = d[pr.second] - (mx[i][0] - pr.second) + (n - i);
		ans += d[i];
//		printf("%d %d\n",i,d[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
