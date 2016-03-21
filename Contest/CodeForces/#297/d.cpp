#include<bits/stdc++.h>
using namespace std;

const int maxn=2000 + 10;
int pic[maxn][maxn];
int n,m;

bool inside(int x,int y)
{
	return x>=0 && x<n && y>=0 && y<m;
}

void change(int x,int y)
{
	if(!inside(x,y)) return;
	int cnt=0;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			cnt+=(pic[x+i][y+j]==0);
	if(cnt==1){
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				pic[x+i][y+j]=1;
		for(int i=-1;i<2;++i)
			for(int j=-1;j<2;++j)
				change(x+i,y+j);
	}
}

int main()
{
	//freopen("test","r",stdin);
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			char c=getchar();
			pic[i][j]=(c=='*')?0:1;
		}
		getchar();
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			change(i,j);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)
			printf(pic[i][j]?".":"*");
		puts("");
	}
	return 0;
}

