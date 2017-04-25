#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

void FWT(LL a[],int l,int r)
{
	if(l == r) return;
	int m = (l+r) >> 1;
	FWT(a,l,m); FWT(a,m+1,r);
	for(int i=0;i<=m-l;++i)
	{
		LL a0 = a[l+i],a1 = a[m+i+1];
		a[l+i] = a0 + a1;
		a[m+i+1] = a0 - a1;
	}
}

void IFWT(LL a[],int l,int r)
{
	if(l == r) return;
	int m = (l+r) >> 1;
	for(int i=0;i<=m-l;++i)
	{
		LL a0 = a[l+i],a1 = a[m+i+1];
		a[l+i] = (a0 + a1)/2;
		a[m+i+1] = (a0 - a1)/2;
	}
	IFWT(a,l,m); IFWT(a,m+1,r);
}

const int maxn = 1e5 + 10;
int n,m;
char s[22][maxn];
LL A[1<<20],B[1<<20];

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);	
	F(i,0,n-1) scanf("%s",s[i]);
	F(j,0,m-1)
	{
		int num = 0;
		F(i,0,n-1) num = (num<<1) + s[i][j] - '0';
		A[num]++;
	}
	F(j,0,(1<<n)-1)
	{
		int cnt = __builtin_popcount(j);
		B[j] = min(cnt,n-cnt);
	}
	FWT(A,0,(1<<n)-1);
	FWT(B,0,(1<<n)-1);
	F(i,0,(1<<n)-1) A[i] *= B[i];
	IFWT(A,0,(1<<n)-1);
	LL ans = n*m;
	F(i,0,(1<<n)-1) ans = min(ans,A[i]);
	printf("%lld\n",ans);
	return 0;
}
