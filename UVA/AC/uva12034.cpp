//f(n)=ΣC(n,i)f(n-i)
#include<cstdio>

typedef long long ll;
const int maxn=1000+5;
const int mod=10056;

ll ans[maxn];
ll C[maxn][maxn];

void cinit()
{
	C[1][0]=C[1][1]=1;
	for(int i=2;i<=1000;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j) C[i][j]= (C[i-1][j]+C[i-1][j-1]) % mod;
	}
}

void init()
{
	cinit();
	ans[0]=1;
	for(int n=1;n<=1000;++n){
	 	ans[n]=0;
		for(int i=1;i<=n;++i) ans[n]=(ans[n]+ans[n-i]*C[n][i]) % mod;
	}
}

int main()
{
	init();
	int T,kase=0;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("Case %d: %lld\n",++kase,ans[n]);
	}
	return 0;
}


