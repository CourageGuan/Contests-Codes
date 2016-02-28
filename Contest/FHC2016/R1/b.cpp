#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int T,L,N,M,D,W[maxn];

bool cal(LL m)
{
	int cnt = 0;
	for(int i=0;i<N;++i) cnt += m/W[i];
	return cnt >= L;
}

LL solve()
{
	sort(W,W+N);
	LL l = 0,r = (LL)L*W[0],res = r;
	while(l <= r)
	{
		LL mid = (l+r)/2;
		if(cal(mid))
		{
			res = mid;
			r = mid - 1;
		}
		else l = mid+1;
	}
	if(M >= L) return res + D;
	vector<LL> V;
	for(int i=0;i<N;++i)
	{
		LL cur = W[i];
		while(cur <= res)
		{
			V.push_back(cur);
			cur += W[i];
		}
	}
	sort(V.begin(),V.end());
	assert(V.size() == L);
	queue<LL> Q;
	for(int i=0;i<V.size();++i)
	{
		LL cur = V[i];
		if(Q.size() < M) Q.push(cur);
		else
		{
			if(Q.front() + D <= V[i]) cur = V[i];
			else cur = Q.front() + D;
			Q.push(cur);
			Q.pop();
		}
		while(Q.front() + D <= cur) Q.pop();
	}
	while(Q.size() != 1)  Q.pop();
//	printf("%d %lld\n",Q.size(),Q.front());
	return Q.front()+D;
}

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("laundro_matt.txt","r",stdin);
	freopen("ans_b.txt","w",stdout);
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d %d %d %d",&L,&N,&M,&D);
		for(int i=0;i<N;++i) scanf("%d",W+i);
		printf("Case #%d: %lld\n",z,solve());
	}
	return 0;
}
