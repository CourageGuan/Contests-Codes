/*行末空格泥垢了，
  回溯法枚举全排列*/
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int n,ans[50],vis[50];

bool is_prime(int n)
{
	if(n==2) return true;
	for(int i=2;i<=(int)sqrt(n)+1;++i)
		if(n%i==0) return false; 
	return true;
}

void solve(int k)
{
	if(k==n && is_prime(ans[n-1]+1)){
			for(int i=0;i<n;++i){
				if(i) printf(" ");
				printf("%d",ans[i]);
			}
			printf("\n");
		return ;
	}
	for(int i=2;i<=n;++i)
			if(!vis[i] && is_prime(ans[k-1]+i)){
				ans[k]=i;
				vis[i]=1;
				solve(k+1);
				vis[i]=0;
			}
}
	

int main()
{
	//freopen("test","r",stdin);
	//freopen("1","w",stdout);
	int kase=0;
	while (scanf("%d",&n)==1){
		if(kase++) printf("\n");
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		printf("Case %d:\n",kase);
		ans[0]=1;
		solve(1);
	}
	return 0;
}

