#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 2010;
char a[maxn],b[maxn];
int n,m,d;
LL dp[maxn][maxn][3];

LL solve()
{
	int i = 0,rem = 0;
	while(i < n && a[i] == b[i])
	{
		int t = a[i] - '0';
		if((i&1 && t!=d) || (!(i&1) && t==d)) return 0;
		rem = (rem*10 + t)%m;
		++i;
	}
	if(i>=n) return rem == 0;
	for(int j=a[i]-'0';j<=b[i]-'0';++j)
	{
		if((i&1 && j!=d) || (!(i&1) && j==d)) continue;
		int r = (rem*10+j)%m;
		if(j == a[i]-'0')
			++dp[i][r][1];
		else if(j == b[i]-'0') 
			++dp[i][r][2];
		else
			++dp[i][r][0];
	}
	++i;
	for(;i<n;++i)
	{
		int L = a[i] - '0',R = b[i] - '0';
		for(int j=0;j<m;++j)
		{
			for(int k=0;k<10;++k)
			{
				if((i&1 && k!=d) || (!(i&1) && k==d)) continue;
				int r = (j*10+k)%m;
				
				dp[i][r][0] = (dp[i][r][0]+dp[i-1][j][0])%mod;
				if(k>=L)
				{
					if(k == L)
						dp[i][r][1] = (dp[i][r][1]+dp[i-1][j][1])%mod;
					else
						dp[i][r][0] = (dp[i][r][0]+dp[i-1][j][1])%mod;
				}
				if(k <= R)
				{
					if(k == R)
						dp[i][r][2] = (dp[i][r][2]+dp[i-1][j][2])%mod;
					else
						dp[i][r][0] = (dp[i][r][0]+dp[i-1][j][2])%mod;
				}
			}
		}
	}
	return (dp[n-1][0][0] + dp[n-1][0][1] + dp[n-1][0][2]) %mod;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&m,&d);	
	scanf("%s %s",a,b);
	n = strlen(a);
	printf("%lld\n",solve());
	return 0;
}


