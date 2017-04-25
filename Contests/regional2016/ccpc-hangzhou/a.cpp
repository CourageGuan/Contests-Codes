#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e5 + 10;
int n,k;
LL a[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d %d",&n,&k);
		LL sum = 0;
		F(i,1,n) scanf("%d",a+i),sum += a[i];
		printf("Case #%d: ",z);
		if(sum%k)
		{
		   	puts("-1");
			continue;
		}
		sum /= k;
		LL cur = 0,ans = 0,lst = 1;
		F(i,1,n)
		{
			cur += a[i];
			if(cur >= sum)
			{
				while(cur >= sum)
				{
					cur -= sum;
					if(cur) ++ans;
				}
				ans += i - lst;
				if(cur) lst = i;
				else lst = i+1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
