#include<bits/stdc++.h>
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<set>
//#include<algorithm>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

set<int> fib;

void init()
{
	LL f1 = 1,f2 = 1,t;
	while(f1 < (1LL<<31))
	{
		t = f1;
		f1 = f1 + f2;
		f2 = t;
		fib.insert(f1);
	}
}

int main()
{
//	freopen("test.txt","r",stdin);
	init();
	int n;
	while(cin >> n && n)
	{
		puts(fib.find(n) == fib.end()?"First win":"Second win");
	}
	return 0;
}
