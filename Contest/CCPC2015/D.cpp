#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int maxl = 2010;
int n,l;
LL d[maxl*2][3];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)	
	{
		scanf("%d %d",&n,&l);
		memset(d,0,sizeof d);
		LL ans = 0;
		for(int i=0;i<n;++i) 
		{
			int a;
			LL	v;
			scanf("%d %lld",&a,&v);
			a*=2;
			ans = max(ans,v);
			for(int j=l*2;j>=a/2;--j)
			{
				if(j-a >= 0)
				{
					d[j][0] = max(d[j][0],d[j-a][0]+v);
					d[j][1] = max(d[j][1],d[j-a][1]+v);
					d[j][2] = max(d[j][2],d[j-a][2]+v);
				}
				d[j][0] = max(d[j][0],d[j-(a/2)][1]+v);
				d[j][1] = max(d[j][1],d[j-(a/2)][2]+v);
				for(int k=0;k<3;++k)  ans = max(ans,d[j][k]);
			}
		}
		printf("Case #%d: %lld\n",z,ans);
	}
	return 0;
}
