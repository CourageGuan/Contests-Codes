#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

struct P{
	int x,y,z;
	P(int x,int y,int z):x(x),y(y),z(z) {}
	P() {}
};
vector<P> cur;
int yes[1<<20],vis[1<<20];

int main()
{
//	freopen("test.txt","r",stdin);
	F(i,1,20) F(j,i+1,20) F(k,j+1,20)
		if(i + j > k) yes[(1<<(i-1))|(1<<(j-1))|(1<<(k-1))] = 1;
	F(i,0,(1<<20)-1)
	{
		for(int s=i;s;s=(s-1)&i)
			if(yes[s])
			{
				vis[i] = 1;
				break;
			}
	}
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		int n,ans = 20;
		scanf("%d",&n);
		F(i,0,(1<<n)-1)
		{
			if(!vis[i]) ans = min(ans,n - __builtin_popcount(i));
		}
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}
