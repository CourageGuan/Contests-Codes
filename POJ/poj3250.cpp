//单调栈
#include<cstdio>
#include<stack>

using namespace std;
typedef long long LL ;
LL ans ;
stack<int> st;

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		while(!st.empty()) st.pop();
		ans = 0;
		while(n--)
		{
			int x;
			scanf("%d",&x);
			while(!st.empty() && st.top() < x) st.pop();
			ans += st.size();
			st.push(x);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
