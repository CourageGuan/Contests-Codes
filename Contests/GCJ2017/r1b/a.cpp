#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


const int maxn = 1e3 + 10;
int d,n;
int k[maxn],s[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d %d",&d,&n);
		double mx = 0;
		for(int i=0;i<n;++i)
		{
		   	scanf("%d %d",k+i,s+i);
			mx = max(mx,1.0*(d - k[i])/s[i]);
		}
		printf("Case #%d: %.10lf\n",z,d/mx);
	}
	return 0;
}
