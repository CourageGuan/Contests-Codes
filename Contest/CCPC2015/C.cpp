#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long  LL;

const LL mod = (1e9) + 7;
const int maxn = 1010 ;

LL bit[maxn][maxn];
int a[maxn],t[maxn],n,m;


void add(int id,int p,LL val)
{
	for(int i=p;i<=n;i += (i&-i))
	{
		bit[id][i] = (bit[id][i]+val) %mod;
	}
}

LL query(int id,int p)
{
	LL res = 0;
	for(int i=p;i>0;i-=(i&-i))
	{
		res = (res+bit[id][i]) %mod;
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;++i) scanf("%d",a+i),t[i] = a[i];
		if(m == 1)
		{
			printf("Case #%d: %lld\n",z,n);
			continue;
		}
		sort(t,t+n);
		int pn = unique(t,t+n) - t;
		LL ans = 0;
		memset(bit,0,sizeof bit);
		for(int i=0;i<n;++i)
		{
			int d = (lower_bound(t,t+pn,a[i]) - t) + 1;
			add(1,d,1);
			for(int j=2;j<=m;++j)
			{
				int cur = query(j-1,d-1);
				if(!cur) continue;
				if(j == m) ans = (ans + cur) %mod;
				else add(j,d,cur);
			}
		}
		printf("Case #%d: %lld\n",z,ans);
	}
	return 0;
}
