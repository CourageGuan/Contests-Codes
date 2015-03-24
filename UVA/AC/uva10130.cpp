//01背包只需要把每个人的背包加在一起
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1000+10;
int d[maxn],v[maxn],w[maxn],c[maxn];

int main()
{
	//freopen("test","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d %d",&w[i],&v[i]);
		scanf("%d",&m);
		int C=0;
		for(int j=0;j<m;++j){
			scanf("%d",&c[j]);
			C=max(C,c[j]);
		}
		memset(d,0,sizeof(d));
		for(int i=0;i<n;++i)
			for(int j=C;j>=v[i];--j)
				d[j]=max(d[j],d[j-v[i]]+w[i]);
		int ans=0;
		for(int i=0;i<m;++i) ans+=d[c[i]];
		printf("%d\n",ans);
	}
	return 0;
}
