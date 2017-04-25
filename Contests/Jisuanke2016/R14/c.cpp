#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

typedef unsigned uint;

const LL mod = 1LL<<32;
const int maxn = 110;
uint ans,d[maxn],p[maxn];
int n,m,t;

int main()
{
	//freopen("test.txt","r",stdin);
	
	while(scanf("%d %d",&n,&m) == 2)
	{
		p[0] = 1;
		p[1] = m;
		for(int i=2;i<=n;++i) p[i] = p[i-1]*m;
		d[1] = m;
		ans = d[1];
		uint cur = (uint)(m-1);
		for(int i=2;i<=n;++i)
		{
			if(i>=10) cur *= (uint)m;
			if(i&1) d[i] = d[i-1]*m;
			else
			{
				d[i] = p[i];
				int t = i;
				while(t/2)
				{
					//printf("%d %d %d\n",d[t/2],p[i-t],d[t/2]*p[i-t]);
					d[i] = ((d[i] - d[t/2]*p[i-t])%mod+mod) %mod;
					t -= 2;
				}
				if(i >= 10)
				{
					d[i] += cur;
				}
			}
//			printf("%d %u\n",i,d[i]);
			ans += d[i];
		}
		printf("%u\n",ans);
	}
	return 0;
}

