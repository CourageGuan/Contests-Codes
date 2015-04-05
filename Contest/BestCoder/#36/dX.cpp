#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
const int mod=1e9+7;


ll C(int n,int m)//计算C(n,m)
{
	ll res = 1;
	for(int i = 1; i <= n-m ; i++)
	{
		res *= (m + i);
		res /= i;
		res %= mod;
	}
	return res;
}

ll solve(int n,int m)
{
	if(m<=1) return 1;
	--m;
	ll res=1;
	for(int i=1;i<n;++i){
		if((n-i)<=i/m) break;
		res+=(C(m+i-1,i-1)-solve(i,m-1))%mod;     //隔板
		res%=mod;
	}
	return res%mod;
}


int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		printf("%lld\b",solve(n,m));	
	}
	return 0;
}
