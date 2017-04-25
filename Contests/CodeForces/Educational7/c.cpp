#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn],p[maxn],n,m;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	p[n-1] = n;
	for(int i=n-2;i>=0;--i)
		if(a[i] == a[i+1]) p[i]= p[i+1];
		else p[i] = i+1;
	for(int i=0;i<m;++i)
	{
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		if(a[l-1] != x)
			printf("%d\n",l);
		else if(p[l-1] <= r-1)
			printf("%d\n",p[l-1]+1);
		else puts("-1");
	}
	return 0;
}
