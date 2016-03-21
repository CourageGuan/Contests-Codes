#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn=50000;
int phi[maxn+5];

int phi_table()
{
	memset(phi,0,sizeof(phi));
	phi[1]=1;
	for(int i=2;i<=maxn;++i) if(!phi[i])
		for(int j=i;j<=maxn;j+=i){
			if(!phi[j]) phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
}

int main()
{
	//freopen("test","r",stdin);
	int n;
	phi_table();
	while(scanf("%d",&n) && n){
		long long ans=0;
		for(int i=2;i<=n;++i) ans+=phi[i];
		printf("%lld\n",2*ans+1);
	}
	return 0;
}
