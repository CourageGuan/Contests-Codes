//莫比乌斯反演+分块
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

#define N 50000
typedef long long ll;
const int maxn=50010;
bool vis[maxn];
int primes[maxn],mu[maxn];

void Mobius(){
	memset(vis,0,sizeof vis);
	int tot=0;
	mu[0]=0;mu[1]=1;
	for(int i=2;i<=N;++i){
		if(!vis[i]){
			primes[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<tot;++j){
			int t=i*primes[j];
			if(t>N) break;
			vis[t]=1;
			if(i%primes[j]==0){
				mu[t]=0;
				break;
			}
			else mu[t]=-mu[i];
		}
	}
	for(int i=2;i<=N;++i) mu[i]+=mu[i-1];
}

ll sum(int a,int b){
	ll ans=0;
	int ran=min(a,b);
	int l=1,r,p1,p2;
	while(l<=ran){
		r=min(min(a/(p1=a/l),b/(p2=b/l)),ran);
		ans+=(ll)p1*p2*(mu[r]-mu[l-1]);
		l=r+1;
	}
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	Mobius();
	int n,a,b,c,d,k;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		//cout<<sum(b,d)<<endl;
		printf("%lld\n",sum(b/k,d/k)-sum((a-1)/k,d/k)-sum((c-1)/k,b/k)+sum((a-1)/k,(c-1)/k));
	}
	return 0;
}

