/*先求fib(%n)的前n^2项，找到循环长度m，(fib[i],fib[i+1]) 重复时
 * 再求 fib[a^b%m]*/
#include<cstdio>
#include<iostream>
using namespace std;

typedef unsigned long long ull;

const int maxn=1000*1000 + 5;

ull qpow(ull a,ull n,int m)
{
	if(n==0) return 1;
	ull x=qpow(a,n/2,m)%m;
	ull res=x*x%m;
	if(n&1) res*=a%m;
	return res%m;
}

ull cal(ull a,ull b,int n)
{
	if(n==1 || a==0) return 0;
	ull fib[maxn];
	fib[0]=fib[1]=1%n;
	int m;
	for(int i=2;i<=2+n*n;++i){
		fib[i]=(fib[i-1]+fib[i-2])%n;
		if(fib[i]==fib[1] && fib[i-1]==fib[0]){
			m=i-1;
			break;
		}
	}
	ull pos=(qpow(a,b,m)-1+m)%m;
	return fib[pos];
}

int main()
{
	//freopen("test","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		ull a,b;int n;
		scanf("%llu %llu %d",&a,&b,&n);
		printf("%llu\n",cal(a,b,n));
	}
	return 0;
}

