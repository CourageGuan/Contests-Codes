/*质因数分解*/
#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;

typedef long long LL;
int cnt;

void try_div_1(LL n)
{
	for(LL i=2;i<=ceil(sqrt(n));++i)
		while(n%i==0){
			n/=i;
			if(cnt++) printf(" x ");
			printf("%lld",i);
		}
	if(n>1){
		if(cnt++) printf(" x ");
		printf("%lld",n);		//n is prime
	}
	printf("\n");
}

void try_div_2(LL n)			//优化
{
	while(n%2==0){
		n=n>>1;
		if(cnt++) printf(" x ");
		printf("%d",2);
	}
	for(LL i=3;i<=ceil(sqrt(n));i+=2)
		while(n%i==0){
			n/=i;
			if(cnt++) printf(" x ");
			printf("%lld",i);
		}
	if(n>1){
		if(cnt++) printf(" x ");
		printf("%lld",n);
	}
	printf("\n");
}

int main()
{
	LL n;
	while(scanf("%lld",&n)==1 && n){
		cnt=0;	
		printf("%lld = ",n);
		if(n==1){
			printf("%lld\n",n);
			continue;
		}
		try_div_2(n);
	}
	return 0;
}

