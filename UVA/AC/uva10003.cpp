//区间dp 
//木棍划分，枚举划分点，当前消耗加上最优子结构消耗
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=100;
const int INF=0x3f3f3f3f;
int a[maxn],d[maxn][maxn],vis[maxn][maxn];

int dp(int i,int j)
{
	if(j-i<=1) return 0;
	int& ans=d[i][j];
	if(vis[i][j]) return ans;
	vis[i][j]=1;
	ans=INF;
	for(int k=i+1;k<j;++k)
		ans=min(ans,dp(i,k)+dp(k,j));

	ans+=a[j]-a[i];
	return ans;
}

int main()
{
	//freopen("test","r",stdin);
	int l,n;
	while(scanf("%d",&l) && l){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		a[0]=0;
		a[n+1]=l;
		memset(vis,0,sizeof(vis));
		printf("The minimum cutting is %d.\n",dp(0,n+1));
	}
	return 0;
}


