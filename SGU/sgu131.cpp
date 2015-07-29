//骨牌覆盖问题
//dfs求出状态转移，然后递推
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;

const int maxn = 1<<10;
LL d[2][maxn];
int t,m,n;

void dfs(int p,int s1,int s2,int b1,int b2)
{
	if(p>m)
	{
	//	printf("%d %d\n",s1,s2);
		if(!b1 && !b2)
		{
			d[t][s1] += d[t^1][s2];
		}
		return;
	}

	dfs(p+1,s1<<1|b1,s2<<1|(1^b2),0,0);  	//00
											//00
											
	if(b1==0) dfs(p+1,s1<<1|1,s2<<1|(1^b2),1,0);				//00
																//11

	if(b1==0 && b2==0) dfs(p+1,s1<<1|1,s2<<1,0,0);				//10
																//10

	if(b1==0 && b2==0)	dfs(p+1,s1<<1|1,s2<<1,1,0);				//10
																//11
																
	if(b1==0) dfs(p+1,s1<<1|1,s2<<1|(1^b2),1,1);	//01
													//11

				
	if(b2==0) dfs(p+1,s1<<1|b1,s2<<1,1,1);	//11
											//01
											
	if(b1==0 && b2==0) dfs(p+1,s1<<1|1,s2<<1,0,1);	//11
													//10
}

int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%d %d",&n,&m)==2)
	{
		if(m>n) swap(m,n);
		memset(d,0,sizeof d);
		d[0][(1<<m)-1] = 1;
		for(int i=1;i<=n;++i)
		{
			t=i&1;
			dfs(1,0,0,0,0);
			memset(d[t^1],0,sizeof d[t^1]);	
		}
		printf("%I64d\n",d[n&1][(1<<m)-1]);
	}
	return 0;
}

