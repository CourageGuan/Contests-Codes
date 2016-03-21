//完全背包递推...
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=10000 + 5;
const int w[]={1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};

typedef long long ll;
ll d[maxn];

void init()
{
	memset(d,0,sizeof(d));
	d[0]=1;
	for(int i=0;i<21;++i)
		for(int j=w[i];j<=maxn-5;++j)
			d[j]+=d[j-w[i]];
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n)==1)
		printf("%lld\n",d[n]);
	return 0;
}
