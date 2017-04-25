#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)

const int maxn = 1e5 + 10;
int a[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int res = 1,cur = 0;
	F(i,1,n)
	{
		scanf("%d",a+i);
		if(a[i] > a[i-1]) ++cur;
		else cur = 1;
		res = max(res,cur);
	}
	printf("%d\n",res);
	return 0;
}
