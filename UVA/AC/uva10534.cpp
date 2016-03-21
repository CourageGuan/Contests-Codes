//LIS的O(nlogn)算法，从两端分别求LIS
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;

const int maxn=10000 + 10;
const int INF=0x7fffffff;
int n,a[maxn],d1[maxn],d2[maxn],g[maxn];

int solve()
{
	for(int i=1;i<=n;++i) g[i]=INF;
	for(int i=0;i<n;++i){
		int k=lower_bound(g+1,g+n+1,a[i])-g;
		d1[i]=k;
		g[k]=a[i];
	}
	for(int i=1;i<=n;++i) g[i]=INF;
	memset(g,0x7f,sizeof(g));
	for(int i=n-1;i>=0;--i){
		int k=lower_bound(g+1,g+n+1,a[i])-g;
		d2[i]=k;
		g[k]=a[i];
	}
	int ans=1;
	for(int i=0;i<n;++i){
		int t=min(d1[i],d2[i]);
		ans=max(ans,2*t-1);
	}
	return ans;
}


int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d",&n)==1){
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		printf("%d\n",solve());
	}
	return 0;
}

