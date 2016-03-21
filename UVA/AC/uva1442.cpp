/*扫描法，从两边分别扫一次，
 * 设初始水位高度为天花板高度，若碰到墙壁或天花板，设其高度为pi或si
 * 每个位置水位高度为两次扫描高度的最小值*/
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=1000000 + 5;

int p[maxn],s[maxn];

int main()
{
	//freopen("test","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int h[maxn];
		int n,ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d",&p[i]);
		for(int i=0;i<n;++i) scanf("%d",&s[i]);
		int level=s[0];
		for(int i=0;i<n;++i){
			if(p[i]>level) level=p[i];
			if(s[i]<level) level=s[i];
			h[i]=level;
		}
		level=s[n-1];
		for(int i=n-1;i>=0;--i){
			if(p[i]>level) level=p[i];
			if(s[i]<level) level=s[i];
			h[i]=min(h[i],level);
			ans+=h[i]-p[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

