#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,a,b) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int main()
{
	//freopen("test.txt","r",stdin);
	int a,b,n;
	DB res = 1e9;
	scanf("%d %d %d",&a,&b,&n);
	while(n--)
	{
		int x,y,v;
		scanf("%d %d %d",&x,&y,&v);
		res = min(res,sqrt((x-a)*(x-a)+(y-b)*(y-b))/v);
	}
	printf("%.9lf\n",res);
	return 0;
}
