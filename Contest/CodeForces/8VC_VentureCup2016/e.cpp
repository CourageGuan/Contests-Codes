#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
int d,n,m,nxt[maxn];

struct P{
	int x,p;
	bool operator<(const P& rhs) const{
		return x < rhs.x;
	}	
} p[maxn];

stack<pair<int,int> > st;
#define mp make_pair

void init()
{
	nxt[m] = -1;
	st.push(mp(0,m));
	for(int i=m-1;i>=0;--i)
	{
		while(!st.empty() && p[i].p < st.top().first) st.pop();
		if(st.empty()) nxt[i] = -1;
		else nxt[i] = st.top().second;
		st.push(mp(p[i].p,i));
	}
}

LL solve()
{
	LL res = 0,cur = n-p[0].x;
	if(p[0].x > n) return -1;
	int i = 0;
	while(i<m)
	{
		if(p[i+1].x - p[i].x > n) return -1;
		if(nxt[i]==-1 || p[nxt[i]].x - p[i].x > n)
		{
			res += (LL)p[i].p*(n-cur);
			cur = n- (p[i+1].x - p[i].x);
			++i;
		}
		else
		{
			res += (LL)p[i].p*max(0LL,(p[nxt[i]].x - p[i].x - cur));
			cur += max(0LL,(p[nxt[i]].x - p[i].x - cur)) - (p[nxt[i]].x - p[i].x);
			i = nxt[i];
		}
	}
	return res;
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d %d",&d,&n,&m);	
	for(int i=0;i<m;++i) scanf("%d %d",&p[i].x,&p[i].p);
	sort(p,p+m);
	p[m].x = d;
	p[m].p = 0;
	init();
	printf("%lld\n",solve());
	return 0;
}
