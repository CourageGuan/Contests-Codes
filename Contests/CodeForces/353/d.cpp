#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int n,a;
set<int> st;
map<int,int> ls,rs;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	scanf("%d",&a);
	st.insert(a);
	F(i,1,n-1)
	{
		scanf("%d",&a);
		auto it = st.upper_bound(a);
		if(it == st.end())
		{
			--it;
			rs[*it] = a;
			printf("%d ",*it);
		}
		else if(!ls[*it])
		{
			ls[*it] = a;
			printf("%d ",*it);
		}
		else
		{
			--it;
			rs[*it] = a;
			printf("%d ",*it);
		}
		st.insert(a);
	}
	puts("");
	return 0;
}
