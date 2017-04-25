#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 5e5 + 10;
LL sum[maxn],mus[maxn];
char s[maxn];
int n,a,b,T;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d%d%d%d",&n,&a,&b,&T);
	scanf("%s",s);
	sum[0] = 0;
	mus[1] = 0;
	for(int i=1;i<=n;++i)
		sum[i] = sum[i-1] + (s[i] == 'h'?1:1+b) + a;
	for(int i=n-1;i>=0;--i)
		mus[n-i] = mus[n-i-1] + (s[i] == 'h'?1:1+b) + a;
	int cnt = 0;
	LL t = T;
	for(int i=1;i<=n;++i)
	{
		t -= (s[i-1] == 'h'?1:1+b);
		if(t < 0) break;
		int cur = upper_bound(mus,mus+n,t-(i-1)*a) - mus - 1;
		cur = max(cur,0);
		cnt = max(cnt,i+cur);
		t -= a;
	}
	t = T;
	t -= (s[0] == 'h'?1:1+b) + a;
	for(int i=n-1;i>=0;--i)
	{
		t -= (s[i] == 'h'?1:1+b);
		if(t < 0) break;
		int cur = upper_bound(sum,sum+n,t-(n-i)*a) - sum - 1;
		cur = max(cur,0);
		cnt = max(cnt,(n-i+1+cur));
		t -= a;
	}
	printf("%d\n",min(n,cnt));
	return 0;
}
