/*唯一分解定理 对n质因数分解, n=a1^p1+a2^p2...
 * 以n为最小公倍数的若干数的最小和即 Σai^pi
 * 可以推广到任意个数的最小和*/
#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;

#define P(a) ((a)*(a))

typedef long long LL;
int cnt;
LL per[1000];

void try_div_2(LL n)			//优化
{
	while(n%2==0){
		n=n>>1;
		per[cnt++]=2;
	}
	for(LL i=3;i<=ceil(sqrt(n));i+=2)
		while(n%i==0){
			n/=i;
			per[cnt++]=i;
		}
	if(n>1){
		per[cnt++]=n;
	}
}

int main()
{
	int kase=0;
	LL n;
	while(scanf("%lld",&n)==1 && n){
		if(n==1){
			printf("Case %d: %lld\n",++kase,2);
			continue;
		}
		LL ans=0;
		cnt=0;
		try_div_2(n);
		int t=0;
		while(t<cnt){
			LL now=per[t++];
			while(t<cnt && per[t]==per[t-1]) now*=per[t++];
			ans+=now;
		}
		if(ans==n) ans++;
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}

