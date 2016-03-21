#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;

const int P[7][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int vis[11][11][11],a[3];


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		for(int i=0;i<3;++i) scanf("%d",a+i);
		memset(vis,0,sizeof vis);
		sort(a,a+3);
		printf("Case #%d:\n",z);
		for(int i=0;i<6;++i)
		{
			if(!vis[a[P[i][0]]][a[P[i][1]]][a[P[i][2]]])
			{
				vis[a[P[i][0]]][a[P[i][1]]][a[P[i][2]]] = 1;
				printf("%d %d %d\n",a[P[i][0]],a[P[i][1]],a[P[i][2]]);
			}
		}
	}
	return 0;
}
