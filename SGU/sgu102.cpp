/*水题,a,b互质即gcd(a,b)==1*/
#include<bits/stdc++.h>
using namespace std;


int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i)
		if(gcd(i,n)==1) ans++;
	printf("%d\n",ans);
	return 0;
}

