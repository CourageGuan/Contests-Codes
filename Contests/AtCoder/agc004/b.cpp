#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof a);

const int maxn = 2010;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int a[2*maxn];
int  n;
LL x;

deque<int> q;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %lld",&n,&x);
	F(i,1,n) scanf("%d",a+i),a[n+i] = a[i];
	LL ans = INF;
	R(k,n)
	{
		while(q.size()) q.pop_back();
		LL res = x*k;
		int r = k+1;
		F(i,1,r) 
		{
			while(!q.empty() && a[q.back()] > a[i]) q.pop_back();
			q.push_back(i);
		}
		while(r <= n+k)
		{
			res += a[q.front()];
			if(a[q.front()] == a[r - k]) q.pop_front();
			++r;
			while(!q.empty() && a[q.back()] > a[r]) q.pop_back();
			q.push_back(r);
		}
//		puts("");
		ans = min(ans,res);
//		printf("%d %d\n",ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
