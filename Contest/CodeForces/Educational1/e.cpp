#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;

int d[33][33][55];

int dp(int n,int m,int k)
{
	if(k == 0 || k == n*m) return 0;
	if(n<m) swap(n,m);
	int &ans = d[n][m][k];
	if(ans != -1) return ans;
	ans = INF;
	for(int i=1;i<m;++i)
	{
		for(int j=0;j<=k;++j)
		{
			if(i*n >=j && (m-i)*n >= k-j)
			{
				ans = min(ans,dp(n,i,j)+dp(n,m-i,k-j)+n*n);
			}
		}
	}

	if(n!=m)
	{
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<=k;++j)
			{
				if(i*m >=j && (n-i)*m >= k-j)
				{
					ans = min(ans,dp(m,i,j)+dp(m,n-i,k-j)+m*m);
				}
			}
		}
	}

	return ans;
}


int main()
{
	//freopen("test.txt","r",stdin);
	int T,ans;
	scanf("%d",&T);
	memset(d,-1,sizeof d);
	while(T--)
	{
		int m,n,k;
		scanf("%d%d%d",&n,&m,&k);
		printf("%d\n",dp(n,m,k));
	}
	return 0;
}
