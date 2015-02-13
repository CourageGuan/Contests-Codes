/*DP  dp[i][j]=max(dp[i][j],dp[i-1][1..j]+a[i][j]) */
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn=100+5;
const int _inf=-0x3f3f3f3f;
int a[maxn][maxn],dp[maxn][maxn],fa[maxn][maxn];

/*
void dfs(int k,int res,bool & yes,int n)
{
	if(k>=f){
		if(res>ans){ 
			ans=res;
			yes=1;
		}
		else yes=0;
		return;
	}
	int pos=0;bool flag=false;
	for(int i=n;i<v;++i){
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,res+a[k][i],yes,n+1);
			if(yes){
				//cout<<k<<" "<<i+1<<endl;
				st[k]=i+1;
				pos=i;
				flag=true;
			}
			vis[i]=0;
		}
	}
	yes=flag;
}
//bool flag=false;
//dfs(0,0,flag,0);
*/

void print(int f,int p){
	if(f<1) return;
	print(f-1,fa[f][p]);
	if(f!=1) printf(" ");
	printf("%d",p);
}

int main()
{
	//freopen("test","r",stdin);
	int f,v;
	scanf("%d%d",&f,&v);
	for(int i=1;i<=f;++i)
		for(int j=1;j<=v;++j) scanf("%d",&a[i][j]);
	memset(dp,_inf,sizeof(dp));
	for(int i=0;i<=v;++i) dp[0][i]=0;
	for(int i=1;i<=f;++i)
		for(int j=i;j<=(v-f+i);++j)
			for(int k=0;k<j;++k)
				if(dp[i-1][k]+a[i][j]>dp[i][j]){
					dp[i][j]=dp[i-1][k]+a[i][j];
					fa[i][j]=k;
				}
	int ans=_inf;int p;
	for(int i=f;i<=v;++i)
		if(dp[f][i]>ans){
			ans=dp[f][i];
			p=i;
		}
	printf("%d\n",ans);
	print(f,p);
	puts("");
	return 0;
}

