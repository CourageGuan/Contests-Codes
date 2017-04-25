#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define P(x) ((x)*(x))

const DB eps = 1e-8;
const DB L = 300;
DB T,V1,V2;

bool yes()
{
	if(V1 == 0) return 0;
	if(V2 == 0 || V1 >= V2) return 1;

	DB x = -1,l = 0,r = L;
	while(r - l > eps)
	{
		DB m = (l+r)/2;
		if((m+L)/V2 >= sqrt(P(m)+P(L))/V1)
		{
			x = m;
			r = m;
		}
		else l = m;
	}

	if(x != -1 && (2*L-x)/V2 + T >= (2*L+x)/V1) return 1;

	x = -1,l=0,r=L;
	while(r - l > eps)
	{
		DB m = (l+r)/2;
		if((m+2*L)/V2 >= sqrt(P(L)+P(L-m))/V1)
		{
			x = m;
			r = m;
		}
		else l = m;
	}

	if(x != -1 && (2*L-x)/V2 + T >= (sqrt(P(L) + P(x)) + 3*L)/V1) return 1;

	return 0;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int kase;
	scanf("%d",&kase);
	F(z,1,kase)
	{
		scanf("%lf %lf %lf",&T,&V1,&V2);
		printf("Case #%d: %s\n",z,yes()?"Yes":"No");
	}
	return 0;
}
