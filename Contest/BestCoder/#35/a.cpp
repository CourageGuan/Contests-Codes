#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b)
{ return b==0?a:gcd(b,a%b);}

int main()
{
	//freopen("test.txt","r",stdin);
	int m,n;
	while(scanf("%d %d",&n,&m)==2){
		printf("%d/%d\n",n*m/gcd(n*m,n+m),(n+m)/gcd(n*m,n+m));
	}
		
	return 0;
}
