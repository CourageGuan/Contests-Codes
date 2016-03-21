#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

const int maxn=5000 + 5;
const int INF=0x3f3f3f3f;
int a[maxn];
ll p[maxn],d[maxn][maxn];

ll dp(int i,int j)
{
	if(i==j) return 0;
	if(i+1==j) return a[i]+a[j];
	ll& ans=d[i][j];
	if(ans!=0) return ans;
	ans=INF;
	for(int k=i;k<j;++k)
		ans=min(ans,dp(i,k)+dp(k+1,j));
	ans+=p[j+1]-p[i];
	return ans;
}

int main()
{
	freopen("test","r",stdin);
	int n;
	while(scanf("%d",&n)==1 && n){
		p[0]=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			p[i+1]=p[i]+a[i];
		}
		memset(d,0,sizeof(d));
		printf("%lld\n",dp(0,n-1));
	}
	return 0;
}


