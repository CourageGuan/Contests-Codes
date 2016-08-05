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


int main()
{
//	freopen("test.txt","r",stdin);
	int t;
	cin >> t;
	int n,m;
	while(t-- && cin >> n >> m) puts(n%(m+1)?"first":"second");
	return 0;
}
