//模拟即可
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=20;
char pic[maxn][maxn];
int n;

bool check(int i,int j,char ch)
{
	if(i>1 && pic[i-1][j]==ch) return false;	
	if(i<n && pic[i+1][j]==ch) return false;	
	if(j>1 && pic[i][j-1]==ch) return false;	
	if(j<n && pic[i][j+1]==ch) return false;	
	return true;
}

int main()
{
	//freopen("test","r",stdin);
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;++kase){
		scanf("%d",&n);
		getchar();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) pic[i][j]=getchar();
			getchar();
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(pic[i][j]=='.')
					for(char ch='A';ch<='Z';++ch)
						if(check(i,j,ch)){
							pic[i][j]=ch;
							break;
						}
		printf("Case %d:\n",kase);
		for(int i=1;i<=n;++i){ 
			for(int j=1;j<=n;++j)
				printf("%c",pic[i][j]);
			puts("");
		}
	}
	return 0;
}
