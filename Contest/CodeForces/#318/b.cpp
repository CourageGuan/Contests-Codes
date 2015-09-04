#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
const int INF = 0x3f3f3f3f;
int a[maxn],n,res[maxn];

void ch(int &a,int b)
{
	if(a>b) a = b;
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n)==1)
	{
		for(int i = 1;i<=n;++i) scanf("%d",a+i);
		a[0] = a[n+1] = 0;
		for(int i=1;i<=n;++i)
		{
			res[i] = a[i];
			ch(res[i],i);
			ch(res[i],n-i+1);
			ch(res[i],res[i-1]+1);
		//	printf("%d %d\n",i,res[i]);
		}
		int ans = 1;
		for(int i=n;i>=1;--i)
		{
			ch(res[i],res[i+1]+1);
			ans = max(ans,res[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
