#include<bits/stdc++.h>
using namespace std;

const int maxn = 4e5+1000;
typedef long long LL;

pair<int,int> A[maxn];
int n,k;


const LL mod = 1e9+7;
LL fac[maxn];

LL pow_mod(LL a,LL p)
{
    LL res = 1;
    while(p)
    {
        if(p&1) res = res*a%mod;
        a = a*a%mod;
        p >>= 1;
    }
    return res;
}


LL GetC(LL n,LL m) //预处理版本　fac[0] = 1;
{
    if(n < m || m < 0) return 0;
    return fac[n]*pow_mod(fac[n-m]*fac[m]%mod,mod-2)%mod;
}


int main()
{
    //freopen("./test.txt","r",stdin);
    fac[0] = 1;
    for(int i = 1;i < maxn/2;++i)
        fac[i] = fac[i-1]*i%mod;


    scanf("%d %d",&n,&k);
    int cur = 0;
    for(int i = 1;i <= n;++i)
    {
        LL L,R;
        scanf("%lld %lld",&L,&R);
        A[cur++] = make_pair(L-1,1);
        A[cur++] = make_pair(R,-1);
    }

    sort(A,A+cur);

    LL prv = -2e9;
    LL now = 0,res = 0;


    for(int i = 0;i < cur;++i)
	{
		res = (res + GetC(now,k)*(A[i].first - prv)%mod)%mod;
		prv = A[i].first;
		now += A[i].second;
	}

    printf("%lld\n",res);
    return 0;
}

