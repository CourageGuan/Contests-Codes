#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxd = 26*26*26;
const int maxn = 1e4 + 10;
vector<string> ans;
int cal[maxn][2];
int vis[maxn];
set<int> d[maxn];
char s[maxn];

void init(int n)
{
	int cur = s[5] - '0';
	for(int i=6;i<n;++i)
	{
		cur %= 26;
		cur *= 26;
		cur += s[i] - '0';
		cal[i-1][0] = cur;
	}
	if(n <= 7) return;
	cur = (s[5] - '0')*26 + (s[6] - '0');
	for(int i=7;i<n;++i)
	{
		cur %= 26*26;
		cur *= 26;
		cur += s[i] - '0';
		cal[i-2][1] = cur;
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s",s);
	int n = strlen(s);
	if(n <= 6)
		puts("0");
	else
	{
		init(n);
		vis[n] = 1;
		string ss(s);
		for(int i=n-2;i>=5;--i)
		{
			if(i+2 <= n && vis[i+2] && i+3<=n && vis[i+3])
			{
				bool flag = 0;
				vis[i] = 1;
				set_intersection(d[i+2].begin(),d[i+2].end(),d[i+3].begin(),d[i+3].end(),inserter(d[i],d[i].begin()));
				if(d[i+2].find(cal[i][0]) == d[i+2].end()) ans.push_back(ss.substr(i,2)),flag = 1;
				if(d[i+3].find(cal[i][1]) == d[i+3].end()) ans.push_back(ss.substr(i,3)),flag = 1;
				if(d[i+2].find(cal[i][1]) != d[i+2].end()) d[i].insert(cal[i][1]);
				if(d[i+3].find(cal[i][0]) != d[i+3].end()) d[i].insert(cal[i][0]);
				if(!flag && !vis[i+5]) vis[i] = 0;
				if(flag && vis[i+5]) set_intersection(d[i+5].begin(),d[i+5].end(),d[i].begin(),d[i].end(),inserter(d[i],d[i].begin()));
			}
			if(i+2 <= n && vis[i+2] && !(i+3<=n && vis[i+3]))
			{
				bool flag = 0;
				vis[i] = 1;
				d[i] = d[i+2];
				if(d[i+2].find(cal[i][0]) == d[i+2].end()) ans.push_back(ss.substr(i,2)),flag = 1;
				d[i].insert(cal[i][0]);
				if(!flag && !vis[i+5]) vis[i] = 0;
				if(flag && vis[i+5]) set_intersection(d[i+5].begin(),d[i+5].end(),d[i].begin(),d[i].end(),inserter(d[i],d[i].begin()));
			}
			if(!(i+2 <= n && vis[i+2]) && i+3<=n && vis[i+3])
			{
				bool flag = 0;
				vis[i] = 1;
				d[i] = d[i+3];
				if(d[i+3].find(cal[i][1]) == d[i+3].end()) ans.push_back(ss.substr(i,3)),flag = 1;
				d[i].insert(cal[i][1]);
				if(!flag && !vis[i+5]) vis[i] = 0;
				if(flag && vis[i+5]) set_intersection(d[i+5].begin(),d[i+5].end(),d[i].begin(),d[i].end(),inserter(d[i],d[i].begin()));
			}
		}
		sort(ans.begin(),ans.end());
		int pn = unique(ans.begin(),ans.end()) - ans.begin();
		printf("%d\n",pn);
		for(int i=0;i<pn;++i) puts(ans[i].c_str());
	}
	return 0;
}
