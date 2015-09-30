#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
int a[maxn],b[11];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,k;
	scanf("%d %d",&n,&k);
	int ans = 0;
	memset(b,0,sizeof b);
	for(int i=0;i<n;++i)
	{
	   	scanf("%d",a+i);
		ans += a[i]/10;
		if(a[i]!=100)
		{
			b[a[i]%10]++;
		}
	}
	for(int i=9;i>=0 && k>0;--i)
	{
		if(k >= (10 - i)*b[i])
		{
			k-= (10 - i)*b[i];
			ans += b[i];
		}
		else
		{
			ans += k/(10-i);
			k = 0;
		}
	}
	ans += k/10;
	printf("%d\n",min(ans,n*10));
	return 0;
}
