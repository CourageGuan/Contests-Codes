//转化后求中位数
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;
const int maxn= 1000000 + 10;
ll C[maxn]; 

int main()
{
	int n; 
	while(scanf("%d",&n)==1){
		ll tot=0,M,a;
		memset(C,0,sizeof(C));
		for(int i=0;i<n;++i){
			scanf("%lld",&a);
			tot+=a;
			C[i+1]=C[i]+a;
		}
		M=tot/n;
		for(int i=1;i<n;++i) C[i]-=i*M; 
		sort(C,C+n);
		//for(int i=0;i<n;++i) cout<<C[i]<<" "; 
		//cout<<endl;
		long long x1=C[n/2],ans=0;
		for(int i=0;i<n;++i) ans+=abs(x1-C[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
