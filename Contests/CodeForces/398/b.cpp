#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=a;i<b;++i)
LL ts,tf,t,over,wait,ans;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1e5 + 10;
LL n,a[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%lld %lld %lld",&ts,&tf,&t);	
	scanf("%lld",&n);
	F(i,0,n) scanf("%lld",a+i);
	if(n == 0)
	{
		printf("%lld\n",ts);
		return 0;
	}
	over = ts;
	wait = INF;
	ans = 0;
	if(a[0] != 0)
	{
		ans = a[0] - 1;
		wait = ts - ans;
	}
	for(int i=0;i<n;++i)
	{
		if(a[i] > over) over = a[i];
		over += t;
		if((i + 1 < n && a[i+1] == a[i]) || a[i] == 0) continue;
		if(over + t > tf) break;
		if(i + 1 < n)
		{
			if(over < a[i+1])
			{
				wait = 0;
				ans = over;
			}
			else
			{
				if(wait > over - (a[i+1]-1))
				{
					wait = over - (a[i+1]-1);
					ans = a[i+1]-1;
				}
			}
		}
		else
		{
			wait = 0;
			ans = over;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
