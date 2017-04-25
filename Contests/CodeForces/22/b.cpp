#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 50;
int cnt[maxn][maxn];
char pic[maxn][maxn];
int n,m;

inline bool yes(int x1,int y1,int x2,int y2)
{
	F(i,x1,x2) F(j,y1,y2)
		if(pic[i][j] == '1') return 0;
	return 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	F(i,1,n)
	{
		scanf("%s",pic[i]+1);
//		puts(pic[i]+1);
	}
	int ans = 0;
	F(i,1,n) F(j,1,m) F(k,i,n) F(l,j,m)
		if(yes(i,j,k,l))
		   	ans = max(ans,(k-i+1)*2 + (l-j+1)*2);
	printf("%d\n",ans);
	return 0;
}
