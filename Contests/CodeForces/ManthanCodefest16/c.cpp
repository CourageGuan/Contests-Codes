#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 786433;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int n,m;

char s[maxn];
vector<int> vis[mod];

char w[maxm][1010];
int lens[maxm];
int d[maxn];
vector<int> ans;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %s %d",&n,s,&m);
	int maxlen = 0;
	for(int i=0;i<m;++i)
	{
		scanf("%s",w[i]);
		int len = strlen(w[i]);
		lens[i] = len;
		int t = 0;
		for(int j=len-1;j>=0;--j)
			t = (t*26 + (tolower(w[i][j]) - 'a')) %mod;
		vis[t].push_back(i);
		maxlen = max(maxlen,len);
	}
	d[0] = -1;
	for(int i=0;i<n;++i)
	{
		if(!d[i]) continue;
		int t = 0;
		for(int j=0;j<maxlen;++j)
		{
			if(i+j >= n) break;
			t = (t*26 + (s[i+j] - 'a')) %mod;
			if(d[i+j+1]) continue;
			for(int k=0;k<vis[t].size();++k)
			{
				if(j+1 == lens[vis[t][k]])
				{
					bool flag = true;
					for(int l=0;l<j;++l) if(s[i+j-l] != tolower(w[vis[t][k]][l])) {flag=false;break;}
					if(!flag) continue;
					d[i+j+1] = vis[t][k]+1;
					break;
				}
			}
		}
	}
	for(int i=n;;i -= lens[d[i]-1])
	{ 
		if(d[i] == -1) break;
		ans.push_back(d[i]-1);
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i) printf("%s ",w[ans[i]]);
	puts("");
	return 0;
}
