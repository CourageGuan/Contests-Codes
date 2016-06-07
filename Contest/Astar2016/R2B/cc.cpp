#pragma comment (linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 10;
int dp[maxn][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	dp[2][2] = 1;
	for(int i=2;i<maxn;++i)
		for(int j=2;j<maxn;++j)
		{
			dp[i][j] = 1;
			for(int r=i-1;r>=2;--r)
				for(int c=j-1;c>=2;--c)
					dp[i][j] += dp[r][c];
		}
	for(int i=1;i<maxn;++i)
	{
		for(int j=1;j<maxn;++j)
			printf("%4d ",dp[i][j]);
		puts("");
	}
	return 0;
}
