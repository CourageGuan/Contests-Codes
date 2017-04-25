#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e4 + 10;
int a[maxn];
int n,k;

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d %d",&n,&k);
		assert(2*k <= n);
		printf("Case #%d: ",z);
		int j = 1;
		if(k == 1)
		{
		   	F(i,1,n) a[i] = i;
			j = n+1;
		}
		else
		{
			if(k&1)
			{
				F(i,2,n)
				{
					if(i==k)
					{
						a[j++] = 1;
						continue;
					}
					if(i==2*k) a[j++] = k;
					a[j++] = i;
				}
			}
			else
			{
				F(i,1,n)
				{
					if(i==k) continue;
					if(i==2*k) a[j++] = k;
					a[j++] = i;
				}
			}
		}
		int sum = 0;
		assert(j == n+1);
		F(i,1,n-1) sum += __gcd(a[i],a[i+1]);
		assert(sum - (n-1) + 1 == k);
		F(i,1,n) printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0;
}
