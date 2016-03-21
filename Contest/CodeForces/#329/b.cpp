#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<LL,LL> > V;

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	LL	x1,x2;
	scanf("%d %lld %lld",&n,&x1,&x2);
	for(int i=0;i<n;++i)
	{
		LL k,b;
		scanf("%lld %lld",&k,&b);
		LL y1 = k*x1+b,y2 = k*x2+b; 
		V.push_back(make_pair(y1,y2));
	}
	sort(V.begin(),V.end());
	for(int i=1;i<V.size();++i)
	{
		if(V[i].second < V[i-1].second)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
