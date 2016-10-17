#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
int a[maxn],l[maxn],r[maxn];
int n;
stack<int> st;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<n;++i)
	{
		while(st.size() && a[st.top()] > a[i]) 
		{
			r[st.top()] = i-1;
			st.pop();
		}
		st.push(i);
	}
	while(st.size())
	{
		r[st.top()] = n-1;
	   	st.pop();
	}
	for(int i=n-1;i>=0;--i)
	{
		while(st.size() && a[st.top()] > a[i]) 
		{
			l[st.top()] = i+1;
			st.pop();
		}
		st.push(i);
	}
	while(st.size())
	{
		l[st.top()] = 0;
	   	st.pop();
	}
	LL ans = 0;
	for(int i=0;i<n;++i)
	{
//		printf("%d %d\n",l[i],r[i]);
		ans += 1LL*(i-l[i]+1)*(r[i]-i+1)*a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
