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

int cnt[110];

int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n),n)
	{
		fill(cnt,0);
		R(i,n)
		{
			int t; 
			scanf("%d",&t);
			cnt[t]++; 
		}
		bool flag = 0;
		F(i,1,100) if(cnt[i]&1) flag = 1; 
		puts(flag?"1":"0");
	}
	return 0;
}
