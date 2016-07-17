#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define P(x) (1LL*(x)*(x)*(x))

pair<LL,LL> cal(LL m)
{
	LL cnt = 0;
	LL mx = 0;
	for(int i=2;;++i)
	{
		LL t = P(i);
		if(t > m) break;
		cnt += m/t;
		mx = max(mx,m/t*t);
	}
	return make_pair(cnt,mx);
}

LL n;

int main()
{
	cin >> n;
	LL l = 8,r = 1e18;
	while(l <= r)
	{
		LL m = (l+r)/2;
		pair<LL,LL> cur = cal(m);
		if(cur.first > n)
		{
			r = m-1;
		}
		else
		{
			l = m+1;
		}
//		printf("%lld %lld\n",l,r);
		if(cur.first == n)
		{
			printf("%lld\n",cur.second);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
