#include<cstdio>
#include<cstring>

long long p[1000];
long long g[1000];

void init()
{
	p[0]=p[1]=p[2]=0;
	g[0]=1;g[1]=2;g[2]=4;
	for(int i=3;i<=60;++i){
		p[i]=1<<(i-3);
		for(int j=2;j<=i-2;++j) p[i]+=g[j-2]*(1<<(i-j-2));
		g[i]=(1<<i)-p[i];
	}
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n) && n) printf("%lld\n",p[n]);
	return 0;
}
