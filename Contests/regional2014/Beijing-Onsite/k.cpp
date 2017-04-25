#include<cstdio>

const int maxn = 1e6 + 10;
int n;
int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		int ans = 0,mn;
		for(int i=0;i<n;++i) scanf("%d",a+i);
		mn = a[n-1];
		for(int i=n-2;i>=0;--i)
		{
			if(a[i] > mn) ++ans;
			else mn = a[i];
		}
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}
