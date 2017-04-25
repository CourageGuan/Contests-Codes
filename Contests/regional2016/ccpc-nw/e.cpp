#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 33;
int n,m;
int a[maxn][maxn];
int cnt[22222];

bool judge()
{
	memset(cnt,0,sizeof cnt);
	F(i,1,n)
	{
		++cnt[a[i][1]];
		if(cnt[a[i][1]] >= 2) 
		{
			return 1;
		}
	}
	memset(cnt,0,sizeof cnt);
	F(i,1,n)
	{
		++cnt[a[i][m]];
		if(cnt[a[i][m]] >= 2) 
		{
			return 1;
		}
	}
	memset(cnt,0,sizeof cnt);
	F(i,1,m)
	{
		++cnt[a[1][i]];
		if(cnt[a[1][i]] >= 2) 
		{
			return 1;
		}
	}
	memset(cnt,0,sizeof cnt);
	F(i,1,m)
	{
		++cnt[a[n][i]];
		if(cnt[a[n][i]] >= 2) 
		{
			return 1;
		}
	}
	F(i,1,n)
	{
		F(j,2,m) if(a[i][j] == a[i][j-1]) return 1;
	}
	F(j,1,m)
	{
		F(i,2,n) if(a[i][j] == a[i-1][j]) return 1;
	}
	return 0;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d %d",&n,&m);
		F(i,1,n) F(j,1,m) scanf("%d",&a[i][j]);
		printf("Case #%d: %s\n",z,judge()?"Yes":"No");
	}
    return 0;
}
