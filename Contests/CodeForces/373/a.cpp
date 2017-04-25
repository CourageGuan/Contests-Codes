#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

int a[100];

int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	if(n == 1)
	{
		if(a[1] == 15) puts("DOWN");
		else if(a[1] == 0) puts("UP");
		else puts("-1");
		return 0;
	}
	else
	{
		if(a[n] == 15) puts("DOWN");
		else if(a[n] == 0) puts("UP");
		else puts(a[n] > a[n-1]?"UP":"DOWN");
	}
	return 0;
}
