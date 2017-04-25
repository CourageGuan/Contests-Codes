#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[20],l,has;
LL n;

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%lld",&n);
		LL t = n;
		has = 0;
		l = 0;
		while(t) a[l++] = t%10,t/=10;
		for(int i=l-1;i>0;--i)
		{
			if(a[i] <= a[i-1]) continue;
			for(int j=i-1;j>=0;--j) a[j] = 9;
			a[i] -= 1;
			for(int j=i;j<l-1;++j) 
			{
				if(a[j] < 0 || a[j] < a[j+1])
				{
					a[j] = 9;
					a[j+1] -= 1;
				}
			}
			break;
		}
		printf("Case #%d: ",z);
		for(int i=a[l-1]>0?l-1:l-2;i>=0;--i) putchar('0'+a[i]);
		puts("");
	}
	return 0;
}
