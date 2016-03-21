#include<cstdio>
#include<cstring>

int ans[10],vis[3][20],n,sum;

void search(int j) 	//column
{
	if(j==n){
		sum++;
		for(int k=0;k<n;++k)
			printf("%d ",ans[k]);
		printf("\n");
	}
	for(int i=0;i<n;++i){	//row
		if(!vis[0][i] && !vis[1][i+j] && !vis[2][j-i+n]){
			ans[j]=i;
			vis[0][i]=vis[1][i+j]=vis[2][j-i+n]=1;
			search(j+1);
			vis[0][i]=vis[1][i+j]=vis[2][j-i+n]=0;
		}
	}
}

int main()
{
	sum=0;
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	search(0);
	printf("%d",sum);
	return 0;
}

