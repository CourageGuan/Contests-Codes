#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define R(i,n) for(int i=(0);i<(n);++i)
#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e4 + 10;
int n,m,vis[maxn];
vector<int> fac;

void init()
{
	memset(vis,0,sizeof(vis));
	fac.clear();
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	R(z,T)
	{
		init();
		scanf("%d %d",&n,&m);
		for(int i=1;i*i <= m;++i)
		{
			if(m%i) continue;
			fac.push_back(i);
			if(i != 1 && i*i != m) fac.push_back(m/i);
		}
		sort(fac.begin(),fac.end());
		R(i,n)
		{
			int x,g;
			scanf("%d",&x);
			g = __gcd(x,m);
			R(j,fac.size()) if(fac[j]%g == 0) vis[j] = 1;
		}
		LL ans = 0;
		R(i,fac.size())
		{
			if(vis[i] == 0) continue;
			LL t = (m-1)/fac[i];
			//printf("%d %d\n",t,fac[i]);
			ans += t*(1+t)/2 * vis[i] * fac[i];
			F(j,i+1,fac.size()-1) if(fac[j] % fac[i] == 0) vis[j] -= vis[i];
		}
		printf("Case #%d: %lld\n",z+1,ans);
	}
	return 0;
}
