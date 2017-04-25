#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;


typedef long long ll;
const int maxn = 1000006;
queue<ll> que;
ll a[maxn];
ll n,t;

int cal(ll k)
{
	ll idx = 0,sum = 0,s;

	while(!que.empty()) que.pop();
	if(n%(k-1) != 1)
	{
		s = n%(k-1);
		if(s == 0) s = k-1;
	}
	else s = k; 

	for(;;)
	{
		ll cost = 0;
		for(int i=0;i<s;++i)
		{
			if(!que.size() && idx >= n) break;
			ll tmp;
			if(!que.empty() && idx < n)
			{
				if(que.front() <= a[idx])
				{
					tmp = que.front();
					que.pop();
				}
				else
				{
					tmp = a[idx];
					++idx;
				}
			}
			else if(que.size() && idx >= n)  
			{
				tmp = que.front();
				que.pop();
			}
			else if(!que.size() && idx < n)
			{
				tmp = a[idx];
				++idx;
			}
			cost += tmp;
		}
		sum += cost;
		if(sum > t) return 0;
		if(!que.size() && idx >= n) break;
		que.push(cost);
		s = k;
	}
	return 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int	kase;
	scanf("%d",&kase);
	for(int i=0;i<kase;++i)
	{
		scanf("%lld %lld",&n,&t);
		for(int i=0;i<n;++i) scanf("%lld",&a[i]);
		sort(a,a+n);
		ll L = 2,R = n,ans;
		for(;L <= R;)
		{
			int M = (L+R)/2;
			if(!cal(M))
				L = M + 1;
			else
			{
				R = M - 1;
				ans = M;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
