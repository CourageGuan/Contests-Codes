#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;
int n,q;
vector<int> e[maxn];
pair<int,int> mn[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%d",&n) == 1)
	{
		for(int i=0;i<n;++i)
		{
			int m,x;
			scanf("%d",&m);
			e[i].clear();
			for(int j=0;j<m;++j) scanf("%d",&x),e[i].push_back(x);
			reverse(e[i].begin(),e[i].end());
		}
		scanf("%d",&q);
		for(int i=0;i<q;++i)
		{
			for(int j=0;j<n;++j) mn[j] = make_pair(0,0);
			int x,y,a,b;
			scanf("%d %d %d %d",&x,&a,&y,&b);
			--x,--y;
			vector<int> t[2];

			a = min(a,(int)e[x].size());
			b = min(b,(int)e[y].size());

			for(int j=1;j<=a;++j)
				t[0].push_back(e[x][e[x].size()-j]);
			for(int j=1;j<=a;++j) e[x].pop_back();
			for(int j=1;j<=b;++j)
				t[1].push_back(e[y][e[y].size()-j]);
			for(int j=1;j<=b;++j) e[y].pop_back();

			for(int j=a-1;j>=0;--j)
				e[y].push_back(t[0][j]);

			for(int j=b-1;j>=0;--j)
				e[x].push_back(t[1][j]);

			for(int j=0;j<n;++j)
			{
				for(int k=e[j].size()-1;k>=0;--k)
				{
				//	printf("%d ",e[j][k]);
					mn[j] = max(mn[j],make_pair((int)(e[j][k]-e[j].size()+k+1),(int)e[j].size()));
				}
				//puts("");
			}
			//puts("");

			sort(mn,mn+n);
			int ans = mn[0].first,cur = mn[0].first+mn[0].second;
			for(int j=1;j<n;++j)
			{
				if(cur < mn[j].first)
				{
					ans += mn[j].first - cur;
					cur = mn[j].first;
				}
				cur += mn[j].second;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
