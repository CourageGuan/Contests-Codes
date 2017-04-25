#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

const DB eps = 1e-8;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a));

int vp,vd,t,f,c;


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d %d",&vp,&vd,&t,&f,&c);
	if(vp >= vd)
	{
		puts("0");
		return 0;
	}
	int res = 0;
	double p = t*vp,d = 0;
	while(p+eps < c)
	{
		p += p/(vd - vp)*vp;
//		printf("%lf\n",p);
		if(p+eps >= c) break;
		++res;
		p += (p/vd+f)*vp;
	}
	printf("%d\n",res);
	return 0;
}
