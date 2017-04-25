#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1010;
int d[maxn][maxn][12][2];
int n,m,k;
char s1[maxn],s2[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m >> k;
	scanf("%s %s",s1+1,s2+1);
	int ans = 0;
	F(i,1,n) F(j,1,m) F(l,1,k)
	{
		if(s1[i] == s2[j])
			d[i][j][l][1] = max(d[i-1][j-1][l][1],d[i-1][j-1][l-1][0]) + 1;

		d[i][j][l][0] = max(d[i-1][j][l][0],d[i][j-1][l][0]);
		d[i][j][l][0] = max(d[i][j][l][0],d[i][j][l][1]);
	}
	printf("%d\n",d[n][m][k][0]);
	return 0;
}
