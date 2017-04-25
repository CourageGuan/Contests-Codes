#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
int a[maxn],n;

bool yes()
{
	F(i,1,n)
	{
		if(!(a[i]&1)) continue;
		if(i == n || !a[i+1]) return 0;
		--a[i+1];
	}
	return 1;
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	puts(yes()?"YES":"NO");
	return 0;
}
