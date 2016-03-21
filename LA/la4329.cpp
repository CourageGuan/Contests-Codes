//树状数组求逆序对...
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int maxn=100010;
ll save[2*maxn],cnt1[2*maxn],cnt2[2*maxn];
ll C[maxn];
int n;

inline void init()
{
	memset(C,0,sizeof C);
}

inline int lowbit(int x){
	return x&-x;
}

inline ll sum(int x){
	ll res=0;
	while(x>0){
		res+=C[x];
		x-=lowbit(x);
	}
	return res;
}

inline void add(int x,int t){
	while(x<maxn){
		C[x]+=t;
		x+=lowbit(x);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
		   	scanf("%d",save+i);
			add(save[i],1);
			cnt1[i]=sum(save[i]-1);
		}
		init();
		for(int i=n;i>=1;--i){
			add(save[i],1);
			cnt2[i]=sum(save[i]-1);
		}
		ll ans=0;
		for(int i=2;i<=n-1;++i)
			ans+=cnt1[i]*(n-i-cnt2[i])+(i-1-cnt1[i])*cnt2[i];
		
		printf("%lld\n",ans);
	}
	return 0;
}




