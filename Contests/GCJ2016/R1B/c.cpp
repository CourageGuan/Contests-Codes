#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 22;
map<string,int> vis[2],cnt[2],vi;
char s[2][maxn];
vector<pair<string,string> > V;
vector<int> tt[16];
int n,m;

int solve()
{
	int res = 0;
	vector<int> t;
	for(int i=0;i<m;++i) t.push_back(i);
	do{
		vis[0].clear();
		vis[1].clear();
		for(int i=0;i<V.size();++i)
			if(!(cnt[0][V[i].first] > 1 && cnt[1][V[i].second] > 1)) vis[0][V[i].first]++,vis[1][V[i].second]++;
		int cur0 = 0;
		for(int j=0;j<t.size();++j)
		{
			int cur1 = 0;
			for(int k=0;k<tt[t[j]].size();++k)
			{
				int c = tt[t[j]][k];
				if(vis[0][V[c].first] && vis[1][V[c].second]) ++cur1;
				vis[0][V[c].first]++;
				vis[1][V[c].second]++;
			}
			cur0 += cur1;
		}
		res = max(res,cur0);
	}while(next_permutation(t.begin(),t.end()));
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("C-small-practice.in","r",stdin);
	freopen("ansC.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		vis[0].clear();
		vis[1].clear();
		for(int i=0;i<2;++i)
			cnt[i].clear(),vis[i].clear();
		vi.clear();
		m = 0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%s %s",s[0],s[1]);
			cnt[0][string(s[0])]++;
			cnt[1][string(s[1])]++;
			V.push_back(make_pair(string(s[0]),string(s[1])));
		}
		sort(V.begin(),V.end());
		for(int i=0;i<V.size();++i)
		{
			if(cnt[0][V[i].first] > 1 && cnt[1][V[i].second] > 1)
			{
				if(!(vi.count(V[i].first))) vi[V[i].first] = m++;
				tt[vi[V[i].first]].push_back(i);
			}
			else vis[0][V[i].first]++,vis[1][V[i].second]++;
		}
		printf("Case #%d: %d\n",z,solve());
	}
	return 0;
}
