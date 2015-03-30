//LCS
#include<stdio.h>
#include<iostream>
using namespace std;

const int maxn=40;
int d[maxn][maxn],a[maxn],b[maxn];

int LCS(int n)
{
	for(int i=0;i<=n;++i) d[i][0]=d[0][i]=0; 
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=max(d[i-1][j],d[i][j-1]);
	return d[n][n];
}

int main()
{
	//freopen("test","r",stdin);
	int n,t;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
	   	scanf("%d",&t);
		a[t]=i;
	}
	while(scanf("%d",&t)==1){
		b[t]=1;
		for(int i=2;i<=n;++i){
		   	scanf("%d",&t);
			b[t]=i;
		}
		printf("%d\n",LCS(n));
	}
	return 0;
}
