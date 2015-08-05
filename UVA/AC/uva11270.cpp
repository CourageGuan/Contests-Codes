//轮廓线dp
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
int n,m,t;
LL d[2][1<<10];

inline void update(int a,int b)
{
	if(b&(1<<m)) d[t][b^(1<<m)] += d[t^1][a];
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n*m &1) puts("0");
		else
		{
			if(n<m) swap(n,m);
			memset(d,0,sizeof d);
			d[0][(1<<m)-1] = 1;
			t = 0;
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<m;++j)
				{
					t^=1;
					memset(d[t],0,sizeof d[t]);
					for(int k=0;k<(1<<m);++k)
					{
						update(k,k<<1);	 //不放
						if(i && !(k&(1<<(m-1)))) update(k,(k<<1)^(1<<m)^1);	 //竖放
						if(j && !(k&1))	update(k,(k<<1)^3);	 //横放
					}
				}
			}
			printf("%lld\n",d[t][(1<<m)-1]);
		}
	}
	return 0;
}

