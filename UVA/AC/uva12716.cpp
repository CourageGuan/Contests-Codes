/* c=gcd(a,b)=a xor b
 * 打印几组解发现c=a-b 只需验证 c==(a^b)
 * c为a的约数,其中枚举c,a的过程需要掌握*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn=30000000;
int p[maxn+5],sum[maxn+5];

int gcd(int a,int b)
{ return (b==0)?a:gcd(b,a%b);}

void init()
{
	memset(p,0,sizeof(p));
	for(int c=1;c<=maxn;++c)
		for(int a=2*c;a<=maxn;a+=c){
			int b=a-c;
			if(c==(a^b)) p[a]++;
		}
	sum[0]=0;
	for(int i=1;i<=maxn;++i) sum[i]=sum[i-1]+p[i];
}

int main()
{
	init();
	int T,kase=0; 
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("Case %d: %d\n",++kase,sum[n]);
	}
	return 0;
}

