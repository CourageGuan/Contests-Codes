#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

int f(int x)
{
	int res = 0;
	for(int i=2;i*i<=x;++i)
	{
		if(x%i == 0)
		{
			while(x%i == 0) x/=i;
			++res;
		}
		if(x == 1) break;
	}
	if(x != 1) ++res;
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n = 100;
	F(i,1,n)
	{
		printf("%d %d\n",i,f(i));
	}
	return 0;
}
