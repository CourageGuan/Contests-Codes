//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1010;
int n,k;
int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	a[0] = -1;
	while(scanf("%d %d",&n,&k) == 2)
	{
		F(i,1,n) scanf("%d",a+i);
		if(k == 1)
		{
			puts("Alice");
			continue;
		}
		int ans = 0;
		for(int j = n;j >= 1; j -= 2)
			ans ^= a[j] - a[j-1] - 1;
		if(n&1 && k == 2)
			ans ^= a[1] ^ (a[1] - 1);

		puts(ans?"Alice":"Bob");
	}
	return 0;
}
