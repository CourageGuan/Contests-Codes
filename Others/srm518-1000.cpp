#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7,inv2 = 5e8 + 4;
const int maxn = 1 << 16;
LL a[maxn];

LL pow_m(LL a,int n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}

void FWT(LL a[],int l,int r)
{
	if(l == r) return;
	int m = (l+r) >> 1;
	FWT(a,l,m); FWT(a,m+1,r);
	for(int i=0;i<=m-l;++i)
	{
		LL a0 = a[l+i],a1 = a[m+i+1];
		a[l+i] = (a0 + a1) %mod;
		a[m+i+1] = (a0 - a1 + mod)%mod;
	}
}

void IFWT(LL a[],int l,int r)
{
	if(l == r) return;
	int m = (l+r) >> 1;
	for(int i=0;i<=m-l;++i)
	{
		LL a0 = a[l+i],a1 = a[m+i+1];
		a[l+i] = (a0 + a1)%mod * inv2 %mod;
		a[m+i+1] = ((a0 - a1 + mod)%mod*inv2) %mod;
	}
	IFWT(a,l,m); IFWT(a,m+1,r);
}

class Nim {
public:
	int count(int K,int L) {
		int len = 1;
		while(len <= L) len <<= 1;
		memset(a,0,sizeof a);
		for(int i=2;i<=L;++i)
			a[i] = 1;
		for(int i=2;i<=L;++i)
			if(a[i])
				for(int j=i+i;j <= L;j+=i) a[j] = 0;
		FWT(a,0,len-1);
		for(int i=0;i<len;++i) a[i] = pow_m(a[i],K);
		IFWT(a,0,len-1);
		return int(a[0]);
	}
};

/*
int main()
{
	//freopen("test.txt","r",stdin);
	Nim n;
	int K,L;
	while(cin >> K >> L)
		cout << n.count(K,L) << '\n';
	return 0;
}
*/
