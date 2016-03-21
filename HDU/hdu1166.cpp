//裸树状数组
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

typedef long long ll;
const int maxn=50010;
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
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;++i){
			int x;
			scanf("%d",&x);
			add(i,x);
		}
		char s[20];
		printf("Case %d:\n",++kase);
		while(scanf("%s",s) && s[0]!='E'){
			int a,b;
			scanf("%d %d",&a,&b);
			if(s[0]=='Q') printf("%d\n",sum(b)-sum(a-1));	
			else if(s[0]=='A') add(a,b);
			else if(s[0]=='S') add(a,-b);
		}
	}
	return 0;
}

