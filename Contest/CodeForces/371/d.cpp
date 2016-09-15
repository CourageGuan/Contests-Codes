#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define R(i,n) for(int i=0;i<(n);++i)
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int x[3][3],y[3][3],n;

void get(int id)
{
	int L = 1,R = n,res = -1,ret;
	while(L <= R)
	{
		int m = (L+R) >> 1;
		printf("? %d %d %d %d\n",1,1,m,n);
		fflush(stdout);
		scanf("%d",&ret);
		if(id == 2 && 1 <= x[1][1] && x[1][2] <= m && 1 <= y[1][1] && y[1][2] <= n) --ret;
		if(ret >= 1)
		{
			res = m;
			R = m - 1;
		}
		else L = m+1;
	}
	x[id][2] = res;
	L = 1,R = res,res = -1;
	while(L <= R)
	{
		int m = (L+R) >> 1;
		printf("? %d %d %d %d\n",m,1,x[id][2],n);
		fflush(stdout);
		scanf("%d",&ret);
		if(id == 2 && m <= x[1][1] && x[1][2] <= x[id][2] && 1 <= y[1][1] && y[1][2] <= n) --ret;
		if(ret >= 1)
		{
			res = m;
			L = m + 1;
		}
		else R = m - 1;
	}
	x[id][1] = res;

	L = 1,R = n,res = -1;
	while(L <= R)
	{
		int m = (L+R) >> 1;
		printf("? %d %d %d %d\n",x[id][1],1,x[id][2],m);
		fflush(stdout);
		scanf("%d",&ret);
		if(id == 2 && x[id][1] <= x[1][1] && x[1][2] <= x[id][2] && 1 <= y[1][1] && y[1][2] <= m) --ret;
		if(ret >= 1)
		{
			res = m;
			R = m - 1;
		}
		else L = m + 1;
	}
	y[id][2] = res;
	L = 1,R = res,res = -1;
	while(L <= R)
	{
		int m = (L+R) >> 1;
		printf("? %d %d %d %d\n",x[id][1],m,x[id][2],y[id][2]);
		fflush(stdout);
		scanf("%d",&ret);
		if(id == 2 && x[id][1] <= x[1][1] && x[1][2] <= x[id][2] && m <= y[1][1] && y[1][2] <= y[id][2]) --ret;
		if(ret >= 1)
		{
			res = m;
			L = m + 1;
		}
		else R = m - 1;
	}
	y[id][1] = res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	get(1);
	get(2);
	printf("! %d %d %d %d %d %d %d %d\n",x[1][1],y[1][1],x[1][2],y[1][2],
		x[2][1],y[2][1],x[2][2],y[2][2]);
	fflush(stdout);
	return 0;
}
