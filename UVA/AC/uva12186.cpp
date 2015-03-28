//树形dp
//dp(i) 返回的是以i为根结点的子树最少提交结点
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100*100*10 + 5;
vector<int> sons[maxn];
int N,T;

int dp(int u)
{
	if(sons[u].empty()) return 1;
	int k=sons[u].size();
	vector<int> d;
	for(int i=0;i<k;++i)
		d.push_back(dp(sons[u][i]));
	sort(d.begin(),d.end());
	int c=(k*T-1)/100+1;
	int ans=0;
	for(int i=0;i<c;++i) ans+=d[i];
	return ans;
}

int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d %d",&N,&T)==2 && N){
		int t;
		for(int i=0;i<=N;++i) sons[i].clear();
		for(int i=1;i<=N;++i){
			scanf("%d",&t);
			sons[t].push_back(i);
		}
		printf("%d\n",dp(0));
	}
	return 0;
}


