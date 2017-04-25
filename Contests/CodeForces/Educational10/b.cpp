#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;
#define R(i,n) for(int i=0;i<(n);++i)
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fill(a,b) memset(a,b,sizeof (a));



int main()
{
//	freopen("test.txt","r",stdin);
	int n,a[1010],b[1010];
	cin >> n;
	R(i,n) cin >> a[i];
	sort(a,a+n);
	R(i,(n+1)/2)
	{
		b[2*i] = a[i];
		b[2*i+1] = a[i+(n+1)/2];
	}
	R(i,n)
		printf("%d ",b[i]);
	return 0;
}
