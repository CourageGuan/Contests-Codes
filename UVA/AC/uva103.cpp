//矩形嵌套...
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

const int maxn=30 + 5;
vector<int> g[maxn];
int n,d[maxn],first;
 

void init()
{
	for(int i=0;i<n;++i) g[i].clear();
	memset(d,0,sizeof(d));
	first=0;
}

bool cmp(int u,int v) 
{
	for(int i=0;i<g[u].size();++i)
	   	if(g[u][i]>=g[v][i]) return false;
	return true;
}

int dp(int u)
{
	if(d[u]) return d[u];
	int& ans=d[u];
	ans=1;
	for(int i=0;i<n;++i){
		if(u==i) continue;
		if(cmp(u,i)) ans=max(ans,dp(i)+1);
	}
	return ans;
}

void print(int u)
{
	if(first++) printf(" ");
	printf("%d",u+1);
	for(int i=0;i<n;++i)
		if(d[u]==d[i]+1 && cmp(u,i)){
			print(i);
			break;
		}
}

int main()
{
	int k;
	while(scanf("%d %d",&n,&k)==2){
		init();
		int u;
		for(int i=0;i<n;++i){
			for(int j=0;j<k;++j){
				scanf("%d",&u);
				g[i].push_back(u);
			}
			sort(g[i].begin(),g[i].end());
		}
		int ans=0,p;
		for(int i=0;i<n;++i)
			if(ans<dp(i)){
			   	ans=dp(i);
				p=i;
			}
		printf("%d\n",ans);
		print(p);
		printf("\n");
	}
	return 0;
}


