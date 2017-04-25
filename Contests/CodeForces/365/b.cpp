#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int n,k;
int c[maxn];
bool vis[maxn];
LL sum,res;


int main()
{
//	freopen("test.txt","r",stdin);
	res = 0;
	sum = 0;
	scanf("%d %d",&n,&k);
	F(i,1,n) scanf("%d",c+i),sum += c[i];
	c[0] = c[n];
	c[n+1] = c[1];
	F(i,1,n) res += c[i]*c[i-1];
	R(i,k)
	{
		int id;
		scanf("%d",&id);
		vis[id] = 1;
		if(id == n) vis[0] = 1;
		if(id == 1) vis[n+1] = 1;
		sum -= c[id];
		res += 1LL*c[id]*(sum - (vis[id-1]?0:c[id-1]) - (vis[id+1]?0:c[id+1]));
	}
	printf("%lld\n",res);
	return 0;
}
