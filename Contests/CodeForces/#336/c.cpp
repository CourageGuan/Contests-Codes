#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int d[maxn][2];
vector<pair<int,int> > V;


int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		V.push_back(make_pair(a,b));
	}
	sort(V.begin(),V.end());
	d[0][0] = 0;
	d[0][1] = 1;
	int ans = 1;
	for(int i=0;i<V.size();++i)
	{
		ans = max(ans,d[i][1]);
		if(i == V.size()-1) break;
		d[i+1][0] = d[i][1];
		int p = lower_bound(V.begin(),V.begin()+i+1,make_pair(V[i+1].first - V[i+1].second,0)) - V.begin();
		if(V[p].first < V[i+1].first - V[i+1].second) d[i+1][1] = d[p][1]+1;
		else if(p != 0) d[i+1][1] = d[p-1][1]+1;
		else d[i+1][1] = 1;
	}
	printf("%d\n",n - ans);
	return 0;
}

