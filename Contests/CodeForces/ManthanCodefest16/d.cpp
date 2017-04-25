#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
int n;
int a[maxn],cnt[maxn];
LL f[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	int pn = 0;
	sort(a,a+n);
	for(int i=0;i<n;++i)
	{
		cnt[pn] = 1;
		a[pn] = a[i];
		while(i+1 < n && a[i] == a[i+1])
		{
			++cnt[pn];
			++i;
		}
		++pn;
	}
	int ans = 2;
	for(int i=0;i<pn;++i)
	{
		--cnt[i];
		for(int j=0;j<pn;++j)
		{
			if(!cnt[j]) continue;
			if(a[i] == 0 && a[j] == 0)
			{
				ans = max(ans,cnt[i]+1);
				continue;
			}
			--cnt[j];
			f[0] = a[i];
			f[1] = a[j];
			int k;
			for(k=2;;)
			{
				f[k] = f[k-1] + f[k-2];
				int p = lower_bound(a,a+pn,f[k]) - a;
				if(p < pn && a[p] == f[k] && cnt[p])
				{
					--cnt[p];
					++k;
				}
				else break;
			}
			ans = max(ans,k);
			while(k > 2)
			{
				--k;
				int p = lower_bound(a,a+pn,f[k]) - a;
				++cnt[p];
			}
			++cnt[j];
		}
		++cnt[i];
	}
	printf("%d\n",ans);
	return 0;
}
