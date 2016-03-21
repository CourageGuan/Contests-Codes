#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	LL a=0,b=0,x;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%lld",&x),a |= x;
	for(int i=0;i<n;++i) scanf("%lld",&x),b |= x;
	printf("%lld\n",a+b);
	return 0;
}
