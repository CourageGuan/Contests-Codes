#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL x[3],y[3];	

int solve()
{
	if(x[0] == x[1] && x[1] == x[2]) return 1;
	if(y[0] == y[1] && y[1] == y[2]) return 1;
	if(x[0] == x[1])
	{
		int mn = min(y[0],y[1]),mx = max(y[0],y[1]);
		if(!(mn < y[2] && y[2] < mx)) return 2;
	}
	if(x[0] == x[2])
	{
		int mn = min(y[0],y[2]),mx = max(y[0],y[2]);
		if(!(mn < y[1] && y[1] < mx)) return 2;
	}
	if(x[2] == x[1])
	{
		int mn = min(y[2],y[1]),mx = max(y[2],y[1]);
		if(!(mn < y[0] && y[0] < mx)) return 2;
	}
	if(y[0] == y[1])
	{
		int mn = min(x[0],x[1]),mx = max(x[0],x[1]);
		if(!(mn < x[2] && x[2] < mx)) return 2;
	}
	if(y[0] == y[2])
	{
		int mn = min(x[0],x[2]),mx = max(x[0],x[2]);
		if(!(mn < x[1] && x[1] < mx)) return 2;
	}
	if(y[2] == y[1])
	{
		int mn = min(x[2],x[1]),mx = max(x[2],x[1]);
		if(!(mn < x[0] && x[0] < mx)) return 2;
	}
	return 3;
}

int main()
{
	//freopen("test.txt","r",stdin);
	for(int i=0;i<3;++i) scanf("%lld %lld",x+i,y+i);
	printf("%d\n",solve());
	return 0;
}
