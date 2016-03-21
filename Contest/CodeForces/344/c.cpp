#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
int a[maxn],n,m;
int t[maxn],r[maxn];
vector<int> V,ans;
multiset<int> st;
multiset<int>::iterator it;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	int cur = 0,p = 0;
	for(int i=0;i<m;++i)
	{
		scanf("%d %d",t+i,r+i);
		while(!V.empty() && r[*(V.end()-1)] <= r[i]) V.pop_back();
		V.push_back(i);
	}
	r[m] = 0;
	for(int i=0;i<V.size();++i)
	{
		if(!i || t[V[i]] != t[V[i-1]]) ans.push_back(V[i]);
	}
    int pn = r[ans[0]];
	st.clear();
	for(int i=0;i<pn;++i) st.insert(a[i]);
	ans.push_back(m);

	for(int i=1;i<ans.size();++i)
	{
		if(t[ans[i-1]] == 1)
		{
			for(int j=r[ans[i-1]]-1;j>=r[ans[i]];--j)
			{
				it = st.end();
				--it;
				a[j] = *it;
				st.erase(it);
			}
		}
		else
		{
			for(int j=r[ans[i-1]]-1;j>=r[ans[i]];--j)
			{
				it = st.begin();
				a[j] = *it;
				st.erase(it);
			}
		}
	}
	for(int i=0;i<n;++i) printf("%d ",a[i]);
	puts("");
	return 0;
}
