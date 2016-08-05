#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 55;
int a[maxn];
int n,l;


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d %d",&n,&l);
		F(i,1,n) scanf("%d",a+i),a[i] = l - a[i];
		a[n+1] = 0;
		int ans = 0;
		for(int i=1;i<=n;i+=2) ans ^= a[i] - a[i+1];
		printf("Case %d: ",z);
		puts(ans?"First Player":"Second Player");
	}
	return 0;
}
