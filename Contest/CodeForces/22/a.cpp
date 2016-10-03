#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 110;
int a[maxn],n;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);	
	F(i,0,n-1) scanf("%d",a+i);
	sort(a,a+n);
	int pn = unique(a,a+n) - a;
	if(pn <= 1) puts("NO");
	else printf("%d\n",a[1]);
	return 0;
}
