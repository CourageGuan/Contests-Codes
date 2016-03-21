//d(i,j) 表示前i个气球实验j次能到的最高楼层
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

const int maxn=100+10;
typedef unsigned long long ll;
ll d[maxn][maxn];
int n;
ll k;

ll dp(int i,int j)
{
	if(i==0 || j==0) return 0;
	ll& ans=d[i][j];
	if(ans) return ans;

	//决策1：上一个气球破了 + 决策2:上一个气球没破
	ans=dp(i-1,j-1)+1 + dp(i,j-1);

	return ans;
}


int main()
{
	while(scanf("%d %lld",&n,&k)==2 && n)
	{
		memset(d,0,sizeof(d));
		int ans=-1;
		for(int i=0;i<64;++i)
			if(dp(n,i)>=k){
			   	ans=i;
				break;
			}
		if(ans==-1) printf("More than 63 trials needed.\n");
		else printf("%d\n",ans);
	}
	return 0;
}

