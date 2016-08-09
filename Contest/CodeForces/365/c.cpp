#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int n;
LL w,u,v;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %lld %lld %lld",&n,&w,&v,&u);	
	DB ans = 0;
	bool flag1,flag2;
	flag1 = flag2 = 1;
	R(i,n)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x*u < y*v) flag1 = 0;
		if(x*u > y*v) flag2 = 0;
		ans = max(ans,1.0*(w-y)/u + 1.0*x/v);
	}
	printf("%.8lf\n",(flag1 || flag2)?1.0*w/u:ans);
	return 0;
}
