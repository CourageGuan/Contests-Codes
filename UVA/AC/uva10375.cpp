#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn=1000000 + 7;

bool vis[maxn];
int e[maxn/10],primes[maxn/10],cnt;

void shai(int n){
	memset(vis,0,sizeof(vis));
	int m=sqrt(n+0.5);
	for(int i=2;i<=m;++i) if(!vis[i])
		for(int j=i*i;j<=n;j+=i) vis[j]=1;
}

void add_integer(int n,int d){		//(求(n)^d 的唯一分解式)
	for(int i=0;i<cnt;++i){
		while(!(n % primes[i])){
			n/=primes[i];
			e[i]+=d;
		}
		if(n<=1) break;
	}
}


void add_factorial(int n,int d) 	//(求(n!)^d 的唯一分解式)
{
	for(int i=1;i<=n;++i) add_integer(i,d);
}

int main()
{
	shai(maxn-7);
	for(int i=2;i<=maxn;++i) if(!vis[i]) primes[cnt++]=i;
	int p,q,r,s;
	//freopen("test","r",stdin);
	while(scanf("%d%d%d%d",&p,&q,&r,&s)==4){
		memset(e,0,sizeof(e));	
		add_factorial(p,1);
		add_factorial(q,-1);
		add_factorial(p-q,-1);
		add_factorial(r,-1);
		add_factorial(s,1);
		add_factorial(r-s,1);
		double ans=1;
		for(int i=0;i<cnt;++i) ans*=pow(primes[i],e[i]);
		printf("%.5lf\n",ans);
	}
	return 0;
}

