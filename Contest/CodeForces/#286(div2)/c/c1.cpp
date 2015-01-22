/*bad brains,leave it until i get kills of dp..*/
#include<bits/stdc++.h>
using namespace std;


const int maxn=30000;
const int M=245;
int dp[maxn+300][1000],gem[maxn];

int main()
{
	freopen("test","r",stdin);
	int n,d,mx=0;
	scanf("%d%d",&n,&d);
	memset(gem,0,sizeof(gem));
	for(int i=0;i<n;++i){
		int v;
		scanf("%d",&v);
		gem[v]++;
	}
	memset(dp,0,sizeof(dp));
	int ans=0;
	for(int i=maxn;i>=d;--i){
		for(int j=d-M;j<=d+M;++j){
			if(j<=0) continue;
			if(j>1)
				dp[i][j]=gem[i]+max(dp[i+j][j],max(dp[i+j+1][j+1],dp[i+j-1][j-1]));
			else if(j==1)
					dp[i][j]=gem[i]+max(dp[i+j][j],dp[i+j+1][j+1]);
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}


