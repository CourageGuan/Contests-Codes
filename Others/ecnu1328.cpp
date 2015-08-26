//poi 2000
//当前状态总可以转移到被分开的两个区间
#include<cstdio>
#include<cstring>

const int maxn = 1010;
int SG[maxn];
int c[3];
bool vis[maxn];

void init()
{
	memset(SG,0,sizeof SG);
	for(int i=1;i<maxn;++i)
	{
		memset(vis,0,sizeof vis);
		for(int t=0;t<3;++t)
		{
			for(int j=c[t];j<=i;++j) vis[SG[j - c[t]]^SG[i - j]] = 1;
		}
		for(int j=0; j< maxn;++j) if(!vis[j])
		{
			SG[i] = j;
			break;
		}
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	int m,p,n;
	while(scanf("%d%d%d",c+0,c+1,c+2) == 3)
	{
		init();
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&n);
			puts(SG[n]?"1":"2");
		}
	}
	return 0;
}
