//树状数组 求逆序对
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int maxn=100010;
int n;
ll S[maxn],C[maxn];

inline void init()
{
	memset(S,0,sizeof S);
	memset(C,0,sizeof C);
}

inline int lowbit(int x){
	return x&-x;
}

inline ll sum_C(int x){ 
	int res=0;
	while(x>0){
		res+=C[x];x-=lowbit(x);
	}
	return res;
}

inline ll sum_S(int x){ 
	ll res=0;
	while(x>0){
		res+=S[x];x-=lowbit(x);
	}
	return res;
}

inline void add(int x,int d,int t){
	while(x<=n){
		S[x]+=d;C[x]+=t;x+=lowbit(x);
	}
}

int main()
{
	while(~scanf("%d",&n)){
		init();
		ll ans=0;
		for(int i=1;i<=n;++i){
			int x;scanf("%d",&x);
			add(x,x,1);
			ll k=i-sum_C(x);	//前i个数中比x大的数的个数
			if(k!=0){
				ll sum=sum_S(n)-sum_S(x);
				ans+=x*k+sum;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}



