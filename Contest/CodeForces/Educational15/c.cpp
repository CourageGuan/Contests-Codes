#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e5 + 10;
int a[maxn],b[maxn];
int n,m;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	F(i,1,n) scanf("%d",a+i);
	F(i,0,m-1) scanf("%d",b+i);
	int res = 0,qm = unique(b,b+m) - b;
//	printf("%d\n",qm);
	F(i,1,n)
	{
		int p = upper_bound(b,b+qm,a[i]) - b; 
		int cur = 0x7fffffff;
//		printf("%d %d\n",p,b[p]);
		if(p) cur = min(cur,a[i]-b[p-1]);
		if(p < qm) cur = min(cur,b[p]-a[i]);
		res = max(res,cur);
	}
	printf("%d\n",res);
	return 0;
}
