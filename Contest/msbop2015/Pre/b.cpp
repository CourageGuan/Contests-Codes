#include<bits/stdc++.h>
using namespace std;

const int mod=100007;
const int maxn=1000+10;

char s[maxn];
int n,d[maxn][maxn];

int dp(int i,int j)
{
	if(i>j) return 0;
	if(i==j) return 1;
	int& ans=d[i][j];
	if(ans) return ans;
	if(s[i]==s[j]) ans=(dp(i+1,j)+dp(i,j-1)+1)%mod;
	else ans=(dp(i+1,j)+dp(i,j-1)-dp(i+1,j-1)+mod)%mod;
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T,kase=0;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		n=strlen(s);
		memset(d,0,sizeof(d));
		printf("Case #%d: %d\n",++kase,dp(0,n-1));
	}
	return 0;
}

