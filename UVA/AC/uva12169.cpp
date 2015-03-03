/*枚举a,b按照公式对比计算即可,
 * 汝佳书上写的用a计算b的方法暂时不会，
 * 代码仓库里面也是这个方法...
 * 先贴下来，慢慢理解
 *
 * 		LL tmp = (LL)x[3] - a*a*x[1];
 * 		LL d, xx;
 * 		gcd(10001, a + 1, d, xx, b);
 * 		if (tmp % d != 0)	continue;
 * 		b = b*(tmp/d);
 * 									*/
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=10000 + 5;
const int mod=10001;

int t,a,b,p[maxn];

void solve()
{
	for(a=0;a<=10000;++a)
		for(b=0;b<=10000;++b){
		bool flag=true;
		for(int j=2;j<=2*t;++j){
			if(j&1){
				if(p[j]!=(a*p[j-1]+b) % mod){
					flag=false;
					break;
				}
			}
			else p[j]=(a*p[j-1]+b) % mod;
		}
		if(flag) return;
	}
}
	

int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d",&t)==1){
		for(int i=1;i<=t;++i) scanf("%d",&p[2*i-1]);
		solve();
		//cout<<a<<" "<<b<<endl;
		for(int i=1;i<=t;++i) printf("%d\n",p[2*i]);
	}
	return 0;
}

