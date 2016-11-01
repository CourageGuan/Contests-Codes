#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 2e4 + 10;
const int maxs = 222;

int n,k;
int cntA[maxn],cntB[maxn],A[maxn],B[maxn];
int sa[maxn],tsa[maxn],rk[maxn],height[maxn];
int ch[maxn],st[maxn];

void SA()
{
	memset(cntA,0,maxs*sizeof(int));
//	for (int i = 0; i < maxs; i ++) cntA[i] = 0;
	for (int i = 1; i <= n; i ++) cntA[ch[i]] ++;
	for (int i = 1; i < maxs; i ++) cntA[i] += cntA[i - 1];
	for (int i = n; i; i --) sa[cntA[ch[i]] --] = i;
	rk[sa[1]] = 1;
	for (int i = 2; i <= n; i ++)
	{
		rk[sa[i]] = rk[sa[i - 1]];
		if (ch[sa[i]] != ch[sa[i - 1]]) rk[sa[i]] ++;
	}
	for (int l = 1; rk[sa[n]] < n; l <<= 1)
	{
		memset(cntA,0,sizeof cntA);
		memset(cntB,0,sizeof cntB);
		//for (int i = 0; i <= n; i ++) cntA[i] = 0;
		//for (int i = 0; i <= n; i ++) cntB[i] = 0;
		for (int i = 1; i <= n; i ++)
		{
			cntA[A[i] = rk[i]] ++;
			cntB[B[i] = (i + l <= n) ? rk[i + l] : 0] ++;
		}
		for (int i = 1; i <= n; i ++) cntB[i] += cntB[i - 1];
		for (int i = n; i; i --) tsa[cntB[B[i]] --] = i;
		for (int i = 1; i <= n; i ++) cntA[i] += cntA[i - 1];
		for (int i = n; i; i --) sa[cntA[A[tsa[i]]] --] = tsa[i];
		rk[sa[1]] = 1;
		for (int i = 2; i <= n; i ++)
		{
			rk[sa[i]] = rk[sa[i - 1]];
			if (A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) rk[sa[i]] ++;
		}
	}
	for (int i = 1, j = 0; i <= n; i ++)
	{
		if (j) j --;
		while (ch[i + j] == ch[sa[rk[i] - 1] + j]) j ++;
		height[rk[i]] = j;
	}
}   

bool check(int m)
{
	int lo,hi;
	lo = hi = sa[1];
	for(int i=2;i<=n;++i)
	{
		if(height[i] >= m)
		{
			lo = min(lo,sa[i]);
			hi = max(hi,sa[i]);
			if(hi - lo >= m) return true;
		}
		else lo = hi = sa[i];
	}	
	return false;
}

int main()
{
//	freopen("input.txt","r",stdin);
	while(~scanf("%d",&n) && n)
	{
		for(int i=1;i<=n;++i) scanf("%d",st+i);
		for(int i=1;i<n;++i) ch[i] = st[i+1] - st[i] + 100;
		--n;
		SA();
		int l = 4,r = n,ans = 0;
		while(l<=r)
		{
			int m = (l+r)>>1;
			if(check(m))
			{
				l = m + 1;
				ans = m;
			}
			else r = m-1;
		}
		printf("%d\n",ans>=4?ans+1:0);
	}
	return 0;
}
