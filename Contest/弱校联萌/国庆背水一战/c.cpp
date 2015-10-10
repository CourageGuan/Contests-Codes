#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;


int main()
{
	//freopen("test.txt","r",stdin);
	int T,Q;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		if(n>m) swap(n,m);
		scanf("%d",&Q);
		printf("Case #%d:\n",z);
		while(Q--)
		{
			int x;
			scanf("%d",&x);
			if(x<=1) puts("0");
			else 
				if(n >= x-1) printf("%d\n",x-1);
			else 
				if(m >= x-1) printf("%d\n",n);
			else
			{
				printf("%d\n",max(0,m-(x-n)+1));
			}
		}
	}
	return 0;
}
