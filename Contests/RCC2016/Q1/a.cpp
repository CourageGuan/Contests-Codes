#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<=n;++i)

char s[4][3] = {"00","01","10","11"};
const int maxn = 21;

int d[maxn][maxn][maxn][maxn][2];

void init()
{
	d[1][0][0][0][0] = 1;
	d[0][1][0][0][1] = 2;
	d[0][0][1][0][0] = 3;
	d[0][0][0][1][1] = 4;
	rep(i,20)
	{
		rep(j,20)
		{
			rep(k,20)
			{
				rep(l,20)
				{
					if(i && d[i-1][j][k][l][0]) d[i][j][k][l][0] = 1;
					if(j && d[i][j-1][k][l][0]) d[i][j][k][l][1] = 2;
					if(k && d[i][j][k-1][l][1]) d[i][j][k][l][0] = 3;
					if(l && d[i][j][k][l-1][1]) d[i][j][k][l][1] = 4;
				}
			}
		}
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a[4];
		for(int i=0;i<4;++i) scanf("%d",a+i);
		vector<int> ans;
		if(d[a[0]][a[1]][a[2]][a[3]][0] || d[a[0]][a[1]][a[2]][a[3]][1])
		{
			int t;
			if(d[a[0]][a[1]][a[2]][a[3]][0]) t = 0;
			else t = 1;
			while(d[a[0]][a[1]][a[2]][a[3]][t])
			{
				int p = d[a[0]][a[1]][a[2]][a[3]][t]-1;
				ans.push_back(p);
				--a[p];
				t = p>1?1:0;
			}
			printf("%s",s[ans[ans.size()-1]]);
			for(int i=ans.size()-2;i>=0;--i)
			{
				putchar(s[ans[i]][1]);
			}
			puts("");
		}
		else puts("impossible");
	}
	return 0;
}

