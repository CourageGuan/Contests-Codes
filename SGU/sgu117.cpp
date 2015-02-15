/*快速幂*/
#include<cstdio>

typedef long long LL;


LL qpow(LL a,LL n,LL m)
{
	if(n==0) return 1;
	LL x=qpow(a,n/2,m);
	LL res=x*x%m;
	if(n&1) res=res*a%m;
	return res;
}

int main()
{
	LL N,M,K;
	int ans=0;
	scanf("%lld %lld %lld",&N,&M,&K);
	while(N--){
		int s;
		scanf("%d",&s);
		if(qpow(s,M,K)==0) ans++;
	}	
	printf("%d\n",ans);
	return 0;
}
