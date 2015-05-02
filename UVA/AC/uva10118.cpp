//位压缩dp或者是记忆化搜索
//用一个二进制basket表示篮子中的糖果。
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int maxn=45;
const int INF=0x3f3f3f3f;
int can[4][maxn],deep[5],d[maxn][maxn][maxn][maxn],n;


int dp(int basket,int candy)
{
	int& ans= d[deep[0]][deep[1]][deep[2]][deep[3]];
	if(ans!=-1) return ans;
	ans=0;
	int sum,t;
	for(int i=0;i<4;++i){
		sum=0;
		++deep[i];
		if(deep[i]<=n){
			if((t= 1<<can[i][deep[i]]) & basket)
				sum=dp(t^basket,candy-1)+1;
			else if(candy<4)
				sum=dp(t|basket,candy+1);
		}
		--deep[i];
		ans=max(ans,sum);
	}
	return ans;
}


int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n)==1 && n){
		for(int j=1;j<=n;++j)
			for(int i=0;i<4;++i) scanf("%d",&can[i][j]);
		memset(d,-1,sizeof(d));
		memset(deep,0,sizeof(deep));
		printf("%d\n",dp(0,0));
	}
	return 0;
}

