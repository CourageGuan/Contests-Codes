#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	LL res = 1,dec = 1;
	for(int i=0;i<n;++i) res = res*27 %mod;
	for(int i=0;i<n;++i) dec = dec*7 %mod;
	printf("%d\n",(int)(((res - dec)%mod + mod)%mod));
	return 0;
}
