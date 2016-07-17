#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5;
const int maxn = 1e5 + 10;
int cur[maxn*2];
vector<pair<int,int> > G[maxn*2];
vector<pair<int,int> > ans;

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		G[y-x+N].push_back(make_pair(x,y));
	}
	for(int i=0;i<=2*N;++i)
		sort(G[i].begin(),G[i].end());
	memset(cur,0,sizeof cur);
	int px = -1,py = -1,p = 0;
	bool flag = true;
	for(int i=0;i<n;++i)
	{
		int w;
		scanf("%d",&w);
		w += N;
		if(cur[w] >= G[w].size() )//|| (G[w][cur[w]].first <= px && G[w][cur[w]].second <= py))
		{
			flag = false;
			break;
		}
		if(flag == false) break;
		px = G[w][cur[w]].first;
		py = G[w][cur[w]].second;
		ans.push_back(G[w][cur[w]++]);
	}
	if(flag)
	{
		puts("YES");
		for(int i=0;i<ans.size();++i)
			printf("%d %d\n",ans[i].first,ans[i].second);
	}
	else puts("NO");
	return 0;
}
