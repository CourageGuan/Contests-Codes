#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 110;
int w[maxn],n,ans;

void solve()
{
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		ans = 0;
		scanf("%d",&n);
		F(i,0,n-1) scanf("%d",w+i);
		sort(w,w+n);
		int l = 0,r = n-1,cnt;
		while(l < r)
		{
			cnt = 1;
			while(cnt*w[r] < 50) ++cnt;
			if(l + cnt - 1 <= r)
			{
			   	l += cnt - 1;
				++ans;
			}
			--r;
		}
		printf("Case #%d: %d\n",z,ans);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	freopen("lazy_loading.txt","r",stdin);
	freopen("b.txt","w",stdout);
	solve();
	return 0;
}
