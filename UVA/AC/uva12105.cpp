//大整数dp，但使用技巧不需要大整数
//d(i,j)表示最多i根火柴拼出余数为j的数的最大位数,p[i][j]记录的是满足该条件的该位上的最大数
//d(i,j)=d(i-match[k],(j*10+k)%m)+1
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int maxn=100 + 10;
const int maxm=3000 + 10;
const int match[]={6,2,5,5,4,5,6,3,7,6};
int d[maxn][maxm],p[maxn][maxm];

int main()
{
	int n,m,kase=0;
	while(scanf("%d",&n) == 1 && n){
		scanf("%d",&m);
		printf("Case %d: ",++kase);	
		for(int i=0;i<=n;++i)
			for(int j=0;j<m;++j){
				int& ans=d[i][j];
				ans=(j==0)?0:-1;
				p[i][j]=-1;
				for(int k=9;k>=0;--k){
					if(i<match[k]) continue;
					int t=d[i-match[k]][(j*10+k)%m];	
					if(t>=0 && t+1>ans){
						ans=t+1;
						p[i][j]=k;
					}
			}
		}
		if(p[n][0]>=0){
			int i=n,j=0;
			for(int k=p[i][j];k>=0;k=p[i][j]){
				printf("%d",k);
				i-=match[k];
				j=(j*10+k)%m;
			}
			puts("");
		}else
			puts("-1");
			
	}
	return 0;
}

