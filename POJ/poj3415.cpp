#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxc = 256;

int n;
int cntA[maxn],cntB[maxn],A[maxn],B[maxn],tsa[maxn];
int sa[maxn],rank[maxn],height[maxn];
char ch[maxn],ss[maxn];

void SA()
{
	memset(cntA,0,maxc*sizeof(int));
	for(int i=1;i<=n;++i) cntA[ch[i]]++;
	for(int i=1;i < maxc;++i) cntA[i] += cntA[i-1];
	for(int i=n;i;--i) sa[cntA[ch[i]] --] = i;

	rank[sa[1]] = 1;
	for(int i=2;i<=n;++i)
	{
		rank[sa[i]] = rank[sa[i-1]];
		if(ch[sa[i]] != ch[sa[i-1]]) rank[sa[i]] ++;
	}
	for(int l=1;rank[sa[n]] < n; l <<= 1)
	{
		for(int i=0;i<=n;++i) cntA[i] = 0;
		for(int i=0;i<=n;++i) cntB[i] = 0;

		for(int i=1;i<=n;++i)
		{
			cntA[A[i] = rank[i]]++;
			cntB[B[i] = (i+l <=n)?rank[i+l]:0]++;
		}
		for(int i=1;i<=n;++i) cntB[i] += cntB[i-1];
		for(int i=n;i;--i) tsa[cntB[B[i]]--] = i;
		for(int i=1;i<=n;++i) cntA[i] += cntA[i-1];
		for(int i=n;i;--i) sa[cntA[A[tsa[i]]]--] = tsa[i];
		rank[sa[1]] = 1;
		for(int i=2;i<=n;++i)
		{
			rank[sa[i]] = rank[sa[i-1]];
			if(A[sa[i]] != A[sa[i-1]] || B[sa[i]] != B[sa[i-1]]) rank[sa[i]]++;
		}
	}
	for(int i=1,j=0;i<=n;++i)
	{
		if(j) --j;
		while(ch[i+j] == ch[sa[rank[i]-1]+j]) ++j;
		height[rank[i]] = j;
	}
}

int k,len;
int ta,tb;
LL suma[maxn],sumb[maxn],ssa[maxn],ssb[maxn];

int main()
{
//	freopen("input.txt","r",stdin);
	while(~scanf("%d",&k) && k)
	{
		scanf("%s %s",ch+1,ss);

		len = strlen(ch+1);
		strcat(ch+1,"#");
		strcat(ch+1,ss);
		n = strlen(ch+1);

		SA();

		ta = tb = 0;

		LL ans = 0;

		height[n+1] = height[n];

		for(int i=1;i<=n;++i)
		{

			int cur = height[i+1];

			//printf("%d %d\n",sa[i],cur);

			if(cur < k)
			{
				if(sa[i] <= len) 
					ans += sumb[tb];
				else 
					ans += suma[ta];
				ta = tb = 0;
				continue;
			}

			if(sa[i] == len+1) continue;

			LL tmp;
			
			if(sa[i] <= len)
			{
				tmp = 1;
				while(ta && cur <= A[ta]) suma[ta] = 0,tmp += ssa[ta--];
				A[++ta] = cur;
				ssa[ta] = tmp;
				suma[ta] = suma[ta-1] + ssa[ta]*(A[ta] - k + 1);

				ans += sumb[tb];

				tmp = 0;
				while(tb && cur <= B[tb]) sumb[tb] = 0,tmp += ssb[tb--];
				if(tmp && (!tb || (tb && B[tb] < cur)))
				{
					B[++tb] = cur;
					ssb[tb] = tmp;
					sumb[tb] = sumb[tb-1] + ssb[tb]*(B[tb]-k+1);
				}

			}
			else
			{
				tmp = 1;
				while(tb && cur <= B[tb]) sumb[tb] = 0,tmp += ssb[tb--];
				B[++tb] = cur;
				ssb[tb] = tmp;
				sumb[tb] = sumb[tb-1] + ssb[tb]*(B[tb] - k + 1);

				if(sa[i] == 6)
					printf("..%d %d\n",ta,suma[ta]);
				ans += suma[ta];

				tmp = 0;
				while(ta && cur <= A[ta]) suma[ta] = 0,tmp += ssa[ta--];
				if(tmp && (!ta || (ta && A[ta] < cur)))
				{
					A[++ta] = cur;
					ssa[ta] = tmp;
					suma[ta] = suma[ta-1] + ssa[ta]*(A[ta]-k+1);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
