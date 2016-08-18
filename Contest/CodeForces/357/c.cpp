#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
#define fi first
#define se second

char op[20];
priority_queue<int,vector<int>,greater<int> > pq;
vector<pair<int,int> > ans;

int main()
{
	//freopen("test.txt","r",stdin);
	int n,x;
	scanf("%d",&n);
	R(i,n)
	{
		scanf("%s",op);
		if(op[0] == 'r')
		{
			if(pq.empty())
			{
				ans.pb(mp(1,1));
			} else pq.pop();
			ans.pb(mp(3,0));
		}
		else if(op[0] == 'i')
		{
			scanf("%d",&x);
			pq.push(x);
			ans.pb(mp(1,x));
		}
		else
		{
			scanf("%d",&x);
			while(!pq.empty() && pq.top() < x)
			{
				ans.pb(mp(3,0));
				pq.pop();
			}
			if(pq.empty() || pq.top() > x)
			{
				ans.pb(mp(1,x));
				pq.push(x);
			}
			ans.pb(mp(2,x));
		}
	}
	printf("%d\n",ans.size());
	R(i,ans.size())
	{
		if(ans[i].fi == 3) puts("removeMin");
		else printf("%s %d\n",ans[i].fi == 1?"insert":"getMin",ans[i].se);
	}
	return 0;
}
