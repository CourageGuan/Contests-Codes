//小心空串...
//SCS
#include<stdio.h>
#include<ctype.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

const int maxn=50;
int cnt,a[maxn],b[maxn],d[maxn][maxn],sum[maxn][maxn];

int SCS(int n,int m){
	memset(sum,0,sizeof(sum));
	for(int i=0;i<=n;++i) d[i][0]=0,sum[i][0]=1;
	for(int i=0;i<=m;++i) d[0][i]=0,sum[0][i]=1;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			d[i][j]=0;
			if(a[i]==b[j]){
			   	d[i][j]=d[i-1][j-1]+1;
				sum[i][j]=sum[i-1][j-1];
			}
			else{
			   	d[i][j]=max(d[i][j-1],d[i-1][j]);
				if(d[i][j-1]==d[i][j]) sum[i][j]+=sum[i][j-1];
				if(d[i-1][j]==d[i][j]) sum[i][j]+=sum[i-1][j];
			}
		}

	return n+m-d[n][m];
}

int main()
{
	//freopen("test","r",stdin);
	int T,kase=0;
	scanf("%d%*c",&T);
	while(T--){
		string s;
		int n,m;
		getline(cin,s);
		n=s.size();
		for(int i=1;i<=n;++i) a[i]=s[i-1];
		getline(cin,s);
		m=s.size();
		for(int i=1;i<=m;++i) b[i]=s[i-1];
		cnt=0;
		printf("Case #%d: %d ",++kase,SCS(n,m));
		printf("%d\n",sum[n][m]);
	}
	return 0;
}

