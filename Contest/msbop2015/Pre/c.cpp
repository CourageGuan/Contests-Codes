#include<bits/stdc++.h>
using namespace std;

const int INF=0x7fffffff;

inline long long dis1(int x,int y)
{
	return x*x+y*y;
}

inline long long dis2(int x,int y)
{
	return abs(x)+abs(y);
}

const int maxn=1000+10;
int px[maxn],py[maxn],cx[maxn],cy[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	long long ans;
	int T,n,m,a,b,kase=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&n,&m,&a,&b);
		for(int i=0;i<a;++i) scanf("%d %d",px+i,py+i);
		for(int i=0;i<b;++i) scanf("%d %d",cx+i,cy+i);
		long long ans=INF;
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j){
				long long res=0;
				for(int k=0;k<a;++k) res+=dis1(i-px[k],j-py[k]);
				long long mn=INF;
				for(int k=0;k<b;++k) mn=min(mn,dis2(i-cx[k],j-cy[k]));
				res+=mn;
				ans=min(res,ans);
			}
		printf("Case #%d: %lld\n",++kase,ans);
	}
	return 0;
}

