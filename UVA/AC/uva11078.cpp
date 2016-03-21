//维护当前值之前的最大值即可
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=100000 + 5; 
const int INF=0x3f3f3f3f;

int main()
{
	//freopen("test","r",stdin);
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int a,ans=-INF,mx;
		scanf("%d",&a);
		mx=a;
		for(int i=1;i<n;++i){
		   	scanf("%d",&a);
			ans=max(mx-a,ans);
			mx=max(a,mx);
		}
		printf("%d\n",ans);
	}
	return 0;	
}
