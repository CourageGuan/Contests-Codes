#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	LL n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		LL m = (LL)log2(n);
		printf("%lld\n",n*(n+1)/2 - 2*((LL)pow(2,m+1)-1));
	}
	return 0;
}
