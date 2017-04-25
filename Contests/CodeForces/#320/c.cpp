#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;

int a,b;

double solve()
{
	int l = 0,r = INF,res=1;
	while(l <= r)
	{
		int m = (l+r)/2;
		if((double)(a+b)/(2*m) >= (double)b)
		{
			l = m+1;
			res = m;
		}
		else r = m-1;
	}
	return (double)(a+b)/(2*res);
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&a,&b)==2)	
	{
		if(a<b) puts("-1");
		else
		{
			printf("%.12lf\n",solve());
		}
	}
	return 0;
}
