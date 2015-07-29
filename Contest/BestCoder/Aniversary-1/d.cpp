//数据太弱，过了,但是这个算法存在问题...
//6 4
//1 2
//2 3
//4 5
//5 6
//
//answer
//5
//
//output
//4
#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 10010;
int vis1[maxn],vis2[maxn];
typedef long long LL;
int n,m;
LL ans;

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(vis1,0,sizeof vis1);
		memset(vis2,0,sizeof vis2);

		scanf("%d %d",&n,&m);
		for(int i=0;i<m;++i)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if(vis1[x])
				++vis1[x],++vis2[y];
			else if(vis2[x]) 
				++vis2[x],++vis1[y];
			else if(vis1[y])
				++vis1[y],++vis2[x];
			else
				++vis2[y],++vis1[x];
		}
		int v1,v2,v0;
		v1 = v2 = v0 = 0;
		for(int i=1;i<=n;++i)
		{
			if(vis1[i]) ++v1;
			else if(vis2[i]) ++v2;
			else ++v0;
		}
		ans = 0;
		for(int i=1;i<=n;++i)
		{
			if(vis1[i]) ans +=	v2-vis1[i];
		}
		while(v0--)
		{
			if(v1>=v2)
			{
				ans+=v1;
				++v2;
			}
			else
			{
				ans+=v2;
				++v1;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}




