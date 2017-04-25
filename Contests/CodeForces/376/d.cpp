#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e6 + 10;
int n,c,x,len;
int cnt[maxn];
vector<int> G[2];

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&c);
	scanf("%d",&len);
	F(i,1,len)
	{
		scanf("%d",&x);
		G[0].push_back(x);
	}

	F(i,2,n)
	{
		scanf("%d",&len);
		G[1].clear();

		F(j,1,len)
		{
			scanf("%d",&x);
			G[1].push_back(x);
		}

		int j = 0;
		while(j < G[0].size() && j < G[1].size() && G[0][j] == G[1][j]) ++j;
		if(j >= G[0].size() || j >= G[1].size())
		{
			if(G[0].size() <= G[1].size()) cnt[0]++,cnt[c]--;
		}
		else
		{
			int l,r;
			if(G[0][j] < G[1][j])
			{
				cnt[0]++;
				cnt[c-G[1][j]+1]--;


				cnt[c-G[0][j]+1]++;
				cnt[c]--;
			}
			else
			{
				cnt[c - G[0][j] + 1]++;
				cnt[c - G[1][j] + 1]--;

			}
		}
		G[0].swap(G[1]);
	}	
	int ans = -1;
	F(i,1,c)
	{
		//printf("%d %d\n",i-1,cnt[i-1]);
		if(cnt[i-1] == n-1)
		{
			ans = i-1;
			break;
		}
	   	cnt[i] += cnt[i-1];
	}
	printf("%d\n",ans);
	return 0;
}

