#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

typedef long long LL;
const int maxn = 2e5 + 10;
int d[maxn][18],a[maxn], n,l[maxn],r[maxn],LOG[maxn];
LL ans[maxn];

void init()
{
	stack<int> st;
	for(int i=0;i<n;++i)
	{
		while(!st.empty() && a[st.top()] > a[i])
		{
			r[st.top()] = i-1;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty())
	{
		r[st.top()] = n-1;
		st.pop();
	}
	for(int i=n-1;i>=0;--i)
	{
		while(!st.empty() && a[st.top()] > a[i])
		{
			l[st.top()] = i+1;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty())
	{
		l[st.top()] = 0;
		st.pop();
	}
	LOG[0] = -1;
	for(int i=1;i<=n;++i)
	{ 
		LOG[i] = LOG[i/2]+1;
		d[i-1][0] = a[i-1];
	}
	for(int j=1;j<=LOG[n];++j)
		for(int i=0; i+(1<<(j-1))-1 < n;++i)
			d[i][j] = max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int rmq(int l,int r)
{
	int k = LOG[r-l+1];
	return max(d[l][k],d[r-(1<<k)+1][k]);
}

int main()
{
//	freopen("test.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i) scanf("%d",a+i);
		init();
		memset(ans,0,sizeof ans);
		for(int i=0;i<n;++i)
		{
			int k = r[i]-l[i]+1;
//			printf("%d %d %d\n",l[i],r[i],rmq(l[i],r[i]));
			ans[k] = max(ans[k],(LL)rmq(l[i],r[i])*a[i]);
		}
		for(int i=n-1;i>=1;--i)
			ans[i] = max(ans[i],ans[i+1]);
		for(int i=1;i<=n;++i)
			cout << ans[i] << '\n';
	}
	return 0;
}
