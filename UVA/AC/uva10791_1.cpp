//n=gcd(a1,a2,...,an)
//求min(Σai)
//将n质因数分解,答案为(Σpi^ei)只有一项时+1
#include<stdio.h>
#include<math.h>
typedef long long ll;

ll solve(ll n){
	if(n==1) return 2;
	ll cnt=0,res=1,ans=0;
	if(n%2==0){
		++cnt;
		while(n!=1 && n%2==0){
			res*=2;
			n/=2;
		}
	}
	if(res!=1) ans+=res;
	ll m=(ll)sqrt(n+0.5);
	for(ll i=3;i<=m;i+=2){
		res=1;
		if(n%i==0){
			++cnt;
			while(n!=1 && n%i==0){
				res*=i;
				n/=i;
			}
		}
		if(res!=1) ans+=res;
		if(n==1) break;
	}
	if(n>1){
		++cnt;
		ans+=n;
	}
	if(cnt<=1) ++ans;
	return ans;
}

int main()
{
	ll n,kase=0;
	while(scanf("%d",&n) && n){
		printf("Case %lld: %lld\n",++kase,solve(n));
	}
	return 0;
}
