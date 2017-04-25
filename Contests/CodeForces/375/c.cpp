#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 4010;
int a[maxn],t[maxn],cnt[maxn],n,m;

int cal(int mid)
{
	memcpy(t,a,sizeof a);
	memset(cnt,0,sizeof cnt);

	F(i,1,n) if(t[i] <= m) ++cnt[t[i]];

	int cg = 0,j = 1;
	F(i,1,n) if(t[i] > m)
	{
		while(j <= m && cnt[j] >= mid) ++j;
		if(j > m) break;
		++cnt[j];
		t[i] = j;
		++cg;
	}
	F(i,1,n)
	{
		if(t[i] > m) continue;
		if(cnt[t[i]] <= mid) continue;
		while(j <= m && cnt[j] >= mid) ++j;
		if(j > m) break;
		--cnt[t[i]];
		++cnt[j];
		t[i] = j;
		++cg;
	}
	return cg;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	F(i,1,n) scanf("%d",a+i);
	int res = n/m,cg = cal(n/m);
	printf("%d %d\n",res,cg);
	F(i,1,n) printf("%d ",t[i]);
	puts("");
	return 0;
}
