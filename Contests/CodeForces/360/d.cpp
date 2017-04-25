#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,k;

LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}

LL lcm(LL a,LL b)
{
	return a/gcd(a,b)*b;
}


int main()
{
	cin >> n >> k;
	LL cur = 1;
	for(int i=0;i<n;++i)
	{
		int c;
		scanf("%d",&c);
		cur = gcd(k,lcm(cur,c));
	}
	puts(cur == k?"Yes":"No");
	return 0;
}
