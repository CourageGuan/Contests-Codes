#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second

const int maxn = 1e5 + 10;
int N,Q;
LL ans[maxn],q[maxn];
map<LL,LL,greater<LL> > mp;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&N,&Q);
	q[0] = N;
	F(i,1,Q) scanf("%lld",q+i);
	LL cur = q[Q];
	mp[cur]++;
	while(Q--)
	{
		if(cur > q[Q])
		{
			cur = q[Q];
			for(auto it = mp.begin();it != mp.end() && it->fi > q[Q]; it = mp.erase(it))
			{
				mp[q[Q]] += it->fi/q[Q] * it->se;
				if(it->fi % q[Q]) mp[it->fi % q[Q]] += it-> se;
			}
		}
	}
	for(int i=N;i;--i)
		ans[i] = ans[i+1] + mp[i];
	F(i,1,N) printf("%lld\n",ans[i]);
	return 0;
}
