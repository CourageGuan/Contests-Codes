#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=1;z<=T;++z)
    {
	long long n;
	scanf("%lld",&n);
	printf("Case #%d: %lld\n",z,(n+1)*n/2-1);
    }
    return 0;
}
