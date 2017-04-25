#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof (a))

const int maxn = 1e5 + 10;
int n,m;
int x[maxn],y[maxn],sx,sy;


int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m;
	LL cur = 1LL*n*n;
	R(i,m)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(!x[a] && !y[b])
			cur -= max(0,2*n-1 - sx - sy);
		else if(!x[a])
			cur -= max(0,n-sy);
		else if(!y[b])
			cur -= max(0,n-sx);
		if(!x[a]) ++sx;
		if(!y[b]) ++sy;
		x[a] = y[b] = 1;
		printf("%lld ",cur);
	}
	return 0;
}
