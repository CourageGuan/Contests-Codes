#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

int main()
{
//	freopen("test.txt","r",stdin);
	int n,m,v,u;
	scanf("%d %d %d",&n,&m,&v);
	if(1LL*(n-2)*(n-1)/2+1 < m || m < n-1) puts("-1");
	else
	{
		int rem = m - n + 1;
		F(i,1,n) if(i != v)
		{
//			s += tostr(i) + ' ' + tostr(v) + '\n';
		   	printf("%d %d\n",i,v);
		}
		if(!rem) return 0;
		u = (v+1);
		if(u > n) u = 1;
		F(i,1,n)
		{
			if(i == v || i == u) continue;
			F(j,i+1,n)
			{
				if(j == v || j == u) continue;
				printf("%d %d\n",i,j);
				--rem;
				if(!rem) break;
			}
			if(!rem) break;
		}
	}
	return 0;
}
