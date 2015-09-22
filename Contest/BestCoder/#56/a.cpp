//先算需要多少个格子 ans += t[i]/64 + 1 - (t[i]%64 == 0);
//然后再算需要多少个背包 ans/36 + 1 - (ans%36==0));
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;

const int maxn = 510;
int n;
int t[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	//jhile(scanf("",)==)
	{
		memset(t,0,sizeof t);
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			t[a] += b;
		}
		int ans = 0;
		for(int i=1;i<=500;++i)
		{
			if(t[i])
			{
				ans += t[i]/64 + 1 - (t[i]%64 == 0);
			}
		}
		printf("%d\n",ans/36 + 1 - (ans%36==0));
	}
	return 0;
}
