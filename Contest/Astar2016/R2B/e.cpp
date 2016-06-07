#include<stdio.h>
#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int n,k,m;
int a[maxn];
pair<int,int> p[maxn];
LL sum[maxn];
multiset<int> st;

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d %d",&n,&k,&m) == 3)
	{
		st.clear();
		for(int i=1;i<=n;++i) scanf("%d",a+i),sum[i] = sum[i-1]+a[i];
		for(int i=0;i<m;++i) scanf("%d %d",&p[i].first,&p[i].second);
		sort(p,p+m);
		int cur = p[0].first,i = 0;
		LL ans = 0;
		while(i < m)
		{
			while(i < m && p[i].first == cur)
			{
				st.insert(p[i].second);
				++i;
			}
			if(st.size() >= k)
			{
				while(st.size() > k) st.erase(st.begin());
				ans = max(ans,sum[*st.begin()] - sum[cur-1]);
			}
			if(i >= m) break;
			cur = p[i].first;
		}
		cout << ans << '\n';
	}
	return 0;
}
