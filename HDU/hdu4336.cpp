#include<bits/stdc++.h>
using namespace std;

#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof (a))

int n;
bool vis[1<<20];
double d[1<<20];
double p[22];

double dfs(int s)
{
	if(vis[s]) return d[s];
	vis[s] = 1;
	d[s] = 0;
	double t = 0;
	R(j,n) if(!(s&(1<<j)))
	{
		d[s] += p[j]*(dfs(s^(1<<j)) + 1);
		t += p[j];
	}
//	if(t == 0) return d[s] = 0;
//	printf("%d %lf\n",s,t);
	d[s] = (d[s] + 1 - t)/t;
	return d[s];
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		R(i,n) scanf("%lf",p+i);
		fill(vis,0);
		d[(1<<n)-1] = 0;
		vis[(1<<n)-1] = 1;
		printf("%.10lf\n",dfs(0));
	}
	return 0;
}

