//二维LIS即向四个方向找最优子结构
//d(x,y)=max(d(x',y')+1 | d(x,y)>d(x',y'));
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int maxn=100 + 10;
const int INF=0x3f3f3f3f;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int d[maxn][maxn],pic[maxn][maxn],n,m;

bool inside(int x,int y)
{ 
	return x>=0 && y>=0 && x<n && y<m;
}

int dp(int x,int y)
{
	int& ans=d[x][y];
	if(ans) return ans;
	for(int k=0;k<4;++k){
		int i=x+dx[k],j=y+dy[k];
		if(inside(i,j) && pic[x][y]>pic[i][j]) ans=max(ans,dp(i,j)+1);
	}
	if(ans<=0) ans=1;
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		memset(d,0,sizeof(d));
		char name[100];
		scanf("%s %d %d",name,&n,&m);
		int ans=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&pic[i][j]);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				ans=max(ans,dp(i,j));
		printf("%s: %d\n",name,ans);
	}
	return 0;
}

