#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 1010;
const int maxs = 256;

int n,k;
int cntA[maxn],cntB[maxn],A[maxn],B[maxn];
int sa[maxn],tsa[maxn],rk[maxn],height[maxn];
char ch[maxn];

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
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",ch+1);
		n = strlen(ch+1);
		SA();
		int ans = 0;
		for(int i=1;i<=n;++i)
		{
			ans += n - sa[i] + 1 - height[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
