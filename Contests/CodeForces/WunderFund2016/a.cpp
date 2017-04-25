#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int n;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	stack<LL> st;
	for(int i=1;i<=n;++i)
	{
		st.push(1);
		while(st.size() > 1)
		{
			LL t1 = st.top(); st.pop();
			LL t2 = st.top(); st.pop();
//			printf("%d %lld %lld\n",i,t1,t2);
			if(t1 == t2) st.push(t1+1);
			else
			{
				st.push(t2);
				st.push(t1);
				break;
			}
		}
	}
	vector<LL> ans;
	while(st.size()) ans.push_back(st.top()),st.pop();
	for(int i=ans.size()-1;i>=0;--i) printf("%lld ",ans[i]);
	return 0;
}
