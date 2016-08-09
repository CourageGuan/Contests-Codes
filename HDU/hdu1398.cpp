#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a));

const int maxn = 310;
int n;
LL cnt[maxn],C[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	while(~scanf("%d",&n) && n)
	{
		fill(cnt,0);
		fill(C,0);
		R(i,n+1) C[i] = 1;
		F(i,2,n)
		{
			if(i*i > n) break;
			R(j,n/(i*i)+1)
			{
				R(k,n+1)
				{
					if(k+i*i*j > n) break;
					cnt[k+i*i*j] += C[k];
				}
			}
			memcpy(C,cnt,sizeof(C));
			fill(cnt,0);
		}
		printf("%lld\n",C[n]);
	}
	return 0;
}
