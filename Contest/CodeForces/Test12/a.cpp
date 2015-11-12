#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	LL a,b,k,L,R;
	scanf("%lld %lld %lld",&k,&a,&b);
	L = (a/k)*k;
	if(L<a) L += k;
	R = (b/k)*k;
	if(R>b) R -= k;
	printf("%lld\n",(R-L)/k+1);
	return 0;
}
