#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
const int INF = 0x3f3f3f3f;
int a[maxn];

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

int main()
{
	freopen("10","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int t = INF,res = 1;
		for(int i=0;i<n;++i) scanf("%d",a+i),t = min(t,a[i]);
		for(int i=1;i*i<=t;++i)
		{
			if(t%i == 0)
			{
				int cur=INF,fi=1;
				for(int j=1;j<n;++j)
					if(a[j]%i)
					{
						if(fi)
						{
							cur = a[j];
							fi = 0;
						}
						else
						{
							cur = gcd(cur,a[j]);
						}
					}
				res = max(res,min(i,cur));
				if(t/i == i) continue;
				int k = t/i;
				cur=INF;
				fi = 1;
				for(int j=1;j<n;++j)
					if(a[j]%k)
					{
						if(fi)
						{
							cur = a[j];
							fi = 0;
						}
						else
						{
							cur = gcd(cur,a[j]);
						}
					}
				res = max(res,min(k,cur));
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

