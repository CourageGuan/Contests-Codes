#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef double DB;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mp make_pair
#define fi first
#define se second

const int maxn = 1e5 + 10;
vector<pair<int,int> > p;
int n,a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n) == 1)
	{
		p.clear();
		F(i,1,n) scanf("%d",a+i);
		int cur = 1;
		F(i,2,n+1)
		{
		   	if(i == n+1 || a[i] <= a[i-1])
			{
				p.push_back(mp(cur,i-1));
				cur = i;
			}
		}
		int ans = p[0].se - p[0].fi + 1 + (p.size() > 1);
		for(int i=1;i<p.size();++i)
		{
			ans = max(ans,p[i].se - p[i].fi + 2);
			if((p[i].fi == p[i].se || a[p[i].fi+1] - 1 > a[p[i-1].se]) || (p[i-1].fi == p[i-1].se || a[p[i-1].se-1] + 1 < a[p[i].fi]) )
				ans = max(ans,p[i].se - p[i-1].fi + 1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
