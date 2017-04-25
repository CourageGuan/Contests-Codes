#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

typedef long double LDB;

map<pair<int,int>,int> mp;
 map<pair<int,int>,int>::iterator it;

const int maxn = 2010;
int n;
int x[maxn],y[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d %d",x+i,y+i),x[i]*=2,y[i]*=2;
	mp.clear();
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		{
//			printf("%d %d\n",(1LL*x[i]+x[j])/2,(1LL*y[i]+y[j])/2);
			mp[make_pair((1LL*x[i]+x[j])/2,(1LL*y[i]+y[j])/2)]++;
		}
	LL res = 0;
	for(it=mp.begin();it!=mp.end();++it)
	{
		int t = it -> second;
//		printf("%d %d %d\n",(it->first).first,(it->first).second,t);
		res += 1LL*t*(t-1)/2;
	}
	printf("%lld\n",res);
	return 0;
}
