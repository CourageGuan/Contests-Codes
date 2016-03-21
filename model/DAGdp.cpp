#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1000 + 5; const int INF=0x3f3f3f3f;
int n,m,first;
int vis[maxn],V[maxn],maxv[maxn],minv[maxn],d[maxn],G[maxn][maxn];

//无固定起点终点 答案为dp(i) 的最大值
int dp1(int i)
{
	int &ans=d[i];
	if(ans>0) return ans;
	ans=1;
	for(int j=1;j<=n;++j) 
		if(G[i][j]) ans=max(ans,dp1(j)+1);
	return ans;
}

void print_ans1(int i)
{
	if(first++) printf(" ");
	printf("%d",i);
	for(int j=1;j<=n;++j)
		if(G[i][j] && d[i] == d[j]+1){
			print_ans1(j);
			break;
		}
}


//固定起点终点 s->0
int dp2(int s)
{
	if(vis[s]) return d[s];
	vis[s]=1;
	int &ans=d[s];
	ans=-INF;
	for(int i=1;i<=n;++i) 
		if(s>=V[i])
			ans=max(ans,dp2(s-V[i])+1);
	return ans;
}

void print_ans2(int d[],int s)
{
	for(int i=1;i<=n;++i) 
		if(s>=V[i] && d[s]==d[s-V[i]]+1){
			if(first++) printf(" ");
			printf("%d",i);
			print_ans2(d,s-V[i]);
			break;
		}
}

void solve(int s)
{
	minv[0]=maxv[0]=0;
	for(int i=1;i<=s;++i)
		minv[i]=INF,maxv[i]=-INF;
	for(int i=1;i<=s;++i)
		for(int j=1;j<=n;++j)
			if(i>=V[j]){
				minv[i]=min(minv[i],minv[i-V[j]]+1);	//或者此处可以记录结点，空间换时间
				maxv[i]=max(maxv[i],maxv[i-V[j]]+1);	//mina[i]=j maxa[i]=j
			}
	printf("%d %d\n",minv[s],maxv[s]);
	first=0;
	print_ans2(minv,s);
	puts("");
	first=0;
	print_ans2(maxv,s);
}

/*
  代入 mina maxa
void print_ans2(int d[],int S)
{
	while(S){
		if(first++) printf(" ");
		printf("%d",d[S]);
		S-=V[d[S]];
	}
}
 */



int main()
{

	//freopen("test","r",stdin);
	int S;
	scanf("%d %d",&n,&S);
	for(int i=1;i<=n;++i) scanf("%d",&V[i]);
	solve(S);
	return 0;
}



