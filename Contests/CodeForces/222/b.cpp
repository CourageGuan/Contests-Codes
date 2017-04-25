#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int n,k;
int a[maxn],b[maxn],c[maxn*2];

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	R(i,n)
	{
		scanf("%d%d",a+i,b+i);
		c[2*i] = a[i];
		c[2*i+1] = b[i];
	}
	sort(c,c+2*n);
	R(i,n) putchar(a[i] <= c[n-1] || i < n/2?'1':'0');
	puts("");
	R(i,n) putchar(b[i] <= c[n-1] || i < n/2?'1':'0');
	return 0;
}
