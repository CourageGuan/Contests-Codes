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

int a,b;

int judge(int a,int b)
{
	if(a > b) swap(a,b);
	if(a == 0) return 0;
	int res = 0;
	for(int i=b/a;i>=1;--i)
	{
		if(!judge(b-i*a,a))
		{
			res = 1;
			break;
		}
	}
	return res;
}

int main()
{
//	freopen("test.txt","r",stdin);
	while(cin >> a >> b && a+b)
	{
		puts(judge(a,b)?"Stan wins":"Ollie wins");
	}
	return 0;
}
