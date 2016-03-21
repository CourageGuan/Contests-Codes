//由于数据随机，根据d(x)d(y)>=d(xy),
//按d(x)排序，选前1000个暴力
//get了一种酷炫的线性筛写法和因数统计方法
#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
#define N 100000
const int maxn=100010;
int fac[maxn],save[maxn];
int primes[maxn],p[maxn];

ll cal(int x,int y){
	ll res=1;
	int c,v;
	for(;x>1 || y>1;){
		c=min(p[x],p[y]);
		v=1;
		for(;p[x]==c;x/=c) ++v;
		for(;p[y]==c;y/=c) ++v;
		res*=v;
	}
	return res;
}

void init()
{
	memset(p,0,sizeof p);
	int tot=0;
	for(int i=2;i<=N;++i){
		if(!p[i]) primes[tot++]=p[i]=i;
		for(int j=0;j<tot && primes[j]<=p[i] && primes[j]<=N/i; ++j) p[i*primes[j]]=primes[j];
	}
	p[1]=N*10;
	for(int i=1;i<=N;++i) fac[i]=cal(i,1);
}

int cmp(const int x,const int y){
	return fac[x]>fac[y];
}	

int main()
{
	//freopen("test.txt","r",stdin);
	init();
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",save+i);
	sort(save,save+n,cmp);
	n=min(n,1000);
	ll ans=fac[save[0]];
	for(int i=0;i<n;++i)
		for(int j=i;j<n;++j){
			ans=max(ans,cal(save[i],save[j]));
		}
	printf("%lld\n",ans);
	return 0;
}

