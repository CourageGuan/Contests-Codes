#pragma comment (linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

const LL mod = 1e9 + 7;

LL pow_mod(LL a,LL n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a%mod;
		a = a*a%mod;
		n>>=1;
	}
	return res;
}

LL GetC(LL n,LL m)
{
    if(n < m) return 0;
    if(m > n-m) m = n-m;
    LL s1 = 1,s2 = 1;
    for(LL i = 0;i < m;++i)
    {
        s1 = (s1*(n-i))%mod;
        s2 = (s2*(i+1))%mod;
    }
    return s1*pow_mod(s2,mod-2)%mod;
}



int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	while(scanf("%d %d",&n,&m) == 2)
	{
		cout << GetC((n-2+m-2),m-2) <<'\n';
	}
	return 0;
}
