#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 110;
int n;
int a[maxn],cnt[maxn];

bool yes(int mx)
{
	if(cnt[mx] == 1) return 0;
	cnt[mx] = 0;
	int cur = mx - 1,i = 0;
	while(cur >= (mx+1)/2)
	{
		if(!(mx&1) && cur == (mx+1)/2)
		{
			if(cnt[cur] < 1) return 0;
			cnt[cur]--;
			cnt[cur+1] = 0;
		}
		else
		{
			if(cnt[cur] < 2) return 0;
			cnt[cur] -= 2;
			cnt[cur+1] = 0;
		}
		--cur;
	}
	for(int i=1;i<=mx;++i) if(cnt[i]) return 0;
	return 1;
}

int main()
{
	scanf("%d",&n);
	int mx = 0;
	for(int i=0;i<n;++i) scanf("%d",a+i),cnt[a[i]]++,mx = max(mx,a[i]);
	puts(yes(mx)?"Possible":"Impossible");
	return 0;
}
