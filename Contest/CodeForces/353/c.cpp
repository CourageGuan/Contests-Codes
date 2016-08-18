#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int n;
LL a[maxn],t[maxn];

map<LL,int> cnt;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);	
	R(i,n) scanf("%lld",a+i);
	LL cur = 0;
	R(i,n) 
	{
		cur += a[i];
		cnt[cur]++;
		t[i] = cur;
//		printf("%d\n",cur);
	}
	int ans = n - cnt[0];
	F(i,1,n)
	{
		ans = min(ans,n - cnt[t[i-1]]);
	}
	printf("%d\n",ans);
	return 0;
}
