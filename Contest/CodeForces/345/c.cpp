#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
int x[maxn],y[maxn],n;
vector<pair<int,int> > V;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d %d",x+i,y+i);
		V.push_back(make_pair(x[i],y[i]));
	}
	sort(x,x+n);
	sort(y,y+n);
	LL res = 0;
	int i = 0;
	while(i < n)
	{
		int cnt = 1;
		while(i < n-1 && x[i+1] == x[i]) ++i,++cnt;
		res += (LL)cnt*(cnt-1)/2;
		++i;
	}
	i = 0;
	while(i < n)
	{
		int cnt = 1;
		while(i < n-1 && y[i+1] == y[i]) ++i,++cnt;
		res += (LL)cnt*(cnt-1)/2;
		++i;
	}
	sort(V.begin(),V.end());
	i = 0;
	while(i < n)
	{
		int cnt = 1;
		while(i < n-1 && V[i+1].first == V[i].first && V[i+1].second == V[i].second) ++i,++cnt;
		res -= (LL)cnt*(cnt-1)/2;
		++i;
	}
	printf("%lld\n",res);
	return 0;
}
