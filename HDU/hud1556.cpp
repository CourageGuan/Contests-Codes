//树状数组,区间更新，单点求值
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

typedef long long ll;
const int maxn=100010;
int C[maxn],n;

inline void init(){
	memset(C,0,sizeof C);	
}

inline int lowbit(int x){
	return x&-x;
}

inline int sum(int x){
	int res=0;
	while(x>0){
		res+=C[x];x-=lowbit(x);
	}
	return res;
}

inline void add(int x,int d){
	while(x<=n){
		C[x]+=d;x+=lowbit(x);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T,kase=0;
	while(~scanf("%d",&n) && n){
		init();
		for(int i=0;i<n;++i){
			int a,b;
			scanf("%d %d",&a,&b);
			add(a,1);
			add(b+1,-1);
		}
		int first=0;
		for(int i=1;i<=n;++i){
			if(first++) printf(" ");
			printf("%d",sum(i));
		}
		puts("");
	}
	return 0;
}



