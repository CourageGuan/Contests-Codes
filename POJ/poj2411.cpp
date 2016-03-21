//状压dp，严格说来是递推
//按两行dfs找出所有的状态，然后根据次递推
#include<cstdio>
#include<cstring>
#include<vector> 
#include<algorithm>

using namespace std;

typedef long long LL;
const int maxn = 11;
int m,n;
LL d[2][1<<maxn];
vector<int> ST[2];

void print(int x)
{
	for(int i=0;i<m;++i)
		putchar(x&(1<<i)?'1':'0');
	puts("");
}

void dfs(int p,int s1,int s2)	//s1 为当前行  s2为上一行
{
	if(p>m)
	{
		ST[0].push_back(s1);
		ST[1].push_back(s2);
		return ;
	}
	dfs(p+1,s1<<1|1,s2<<1);	 //竖放，必要条件是上一行为空 
	dfs(p+1,s1<<1,s2<<1|1);	//空白，必要条件是上一行被占
	if(p<=m-1) dfs(p+2,s1<<2|3,s2<<2|3);	//横放，必要条件是上两行被占
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&m,&n) == 2 && m && n)
	{
		if(n&1 && m&1)
		{
		   	puts("0");
			continue;
		}
		if(m>n) swap(m,n);
		for(int i=0;i<2;++i) ST[i].clear();
        dfs(1,0,0);
		memset(d,0,sizeof d);
		d[0][(1<<m)-1] = 1;
        for(int i=1;i<=n;++i)
		{
			for(int j=0;j<ST[0].size();++j)
			{
				d[i&1][ST[0][j]] += d[(i&1)^1][ST[1][j]];
			}
			memset(d[(i&1)^1],0,sizeof(d[(i&1)^1]));
		}
		printf("%lld\n",d[n&1][(1<<m)-1]);
	}
	return 0;
}

