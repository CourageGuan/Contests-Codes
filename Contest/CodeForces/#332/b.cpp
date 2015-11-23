#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;

const int maxn = 1e5 + 10;
int f[maxn],b[maxn];
vector<int> pos[maxn];
int ans[maxn];
int n,m;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);	
	for(int i=0;i<n;++i)
	{
		scanf("%d",f+i);
		pos[f[i]].push_back(i);
	}
	int flag = 2;
	for(int i=0;i<m;++i)
	{
		scanf("%d",b+i);
		if(pos[b[i]].size() == 0)
		{
			flag = 0;
		}
		if(flag == 0) continue;
		if(pos[b[i]].size() > 1)
		{
			flag = 1;
		}
		else ans[i] = pos[b[i]][0] + 1;
	}
	if(flag == 0)
	{
		puts("Impossible");
	}
	else if(flag == 1)
	{
		puts("Ambiguity");
	}
	else
	{
		puts("Possible");
		for(int i=0;i<m;++i) 
			printf("%d%c",ans[i],i == m-1?'\n':' ');
	}
	return 0;
}
