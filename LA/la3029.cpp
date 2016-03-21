//最大子矩阵
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=1000+5;
int pic[maxn][maxn];
int l[maxn][maxn],r[maxn][maxn],u[maxn][maxn];
int n,m;

int main()
{
	//freopen("test","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		getchar();
		char c;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				c=getchar();
				while(c!='F' && c!='R') c=getchar();
				pic[i][j]=(c=='F')?0:1;
				//if(i && pic[i][j] && pic[i-1][j]) pic[i][j]=pic[i-1][j]+1;
			}
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j) 
				if(!pic[j][i]) u[j][i]= j==0 ? 1:u[j-1][i]+1;
				else u[j][i]=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j) 
				if(!pic[i][j]) l[i][j]=(j==0 || u[i][j]>u[i][j-1])?1:l[i][j-1]+1;
				else l[i][j]=0;
								
		for(int i=0;i<n;++i)
			for(int j=m-1;j>=0;--j) 
				if(!pic[i][j]) r[i][j]=(j==m-1 || u[i][j]>u[i][j+1])?1:r[i][j+1]+1;
				else r[i][j]=0;
		
		int ans=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(!pic[i][j]) ans=max(ans,(l[i][j]+r[i][j]-1)*u[i][j]);
		printf("%d\n",3*ans);
		/*for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)
				printf("%d",l[i][j]);
			puts("");
		}*/
	}
	return 0;
}

