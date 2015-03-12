// 1^2 + 2^2 + ... + n^2 = n(n+1)(2n+1)/6
// 1 2 2 3 3 4 4 4 5 5 5 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 ...
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

inline ll cal(ll n)
{
	return n*(n+1)*(2*n+1)/6;
}


int main()
{
	ll n;
	while(scanf("%lld",&n) && n){
		ll l=0,r=n;
		while(l<r){
			ll m=l+(r-l)/2;
			if(cal(m)>=n) r=m;
			else l=m+1;
		}
		l-=1;
		ll g=(1+l)*l/2;
		//cout<<g<<endl;
		ll t=(n-cal(l)+l)/(l+1);
		printf("%lld\n",g+t);
	}
	return 0;
}
