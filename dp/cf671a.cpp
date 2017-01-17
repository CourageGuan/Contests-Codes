#include<bits/stdc++.h>
using namespace std;
typedef double DB;

#define P(x) (1LL*(x)*(x))
#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e5 + 10;
int x[maxn],y[maxn];
int a[2],b[2],t[2],n;
DB d[2][2][2];

inline DB dis(int X,int Y,int i)
{
	return sqrt(P(x[i]-X) + P(y[i]-Y));
}

inline void update(DB& x,DB y)
{
	if(x > y) x = y;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d %d %d",a,a+1,b,b+1,t,t+1);
	scanf("%d",&n);
	F(i,0,n-1)
	{
	   	scanf("%d %d",x+i,y+i);
	}
	F(i,0,1) F(j,0,1) F(k,0,1) d[i][j][k] = 1e18;
	int p = 0;
	d[0][0][0] = 2*dis(t[0],t[1],0);
	d[0][1][0] = dis(a[0],a[1],0)+dis(t[0],t[1],0);
	d[0][0][1] = dis(b[0],b[1],0)+dis(t[0],t[1],0);
	F(i,1,n-1)
	{
		p ^= 1;
		F(j,0,1) F(k,0,1) d[p][j][k] = 1e18;
		update(d[p][0][0],d[p^1][0][0]+2*dis(t[0],t[1],i));

		update(d[p][1][0],d[p^1][1][0]+2*dis(t[0],t[1],i));
		update(d[p][1][0],d[p^1][0][0]+dis(a[0],a[1],i)+dis(t[0],t[1],i));

		update(d[p][0][1],d[p^1][0][1]+2*dis(t[0],t[1],i));
		update(d[p][0][1],d[p^1][0][0]+dis(b[0],b[1],i)+dis(t[0],t[1],i));

		update(d[p][1][1],d[p^1][1][1]+2*dis(t[0],t[1],i));
		update(d[p][1][1],d[p^1][0][1]+dis(a[0],a[1],i)+dis(t[0],t[1],i));
		update(d[p][1][1],d[p^1][1][0]+dis(b[0],b[1],i)+dis(t[0],t[1],i));
	}
	DB ans = 1e18;
	update(ans,d[p][1][0]);
	update(ans,d[p][0][1]);
	update(ans,d[p][1][1]);
	printf("%.10lf\n",ans);
	return 0;
}
