/*中途相遇法,思想是结果暂存，空间换时间,O(n^4)==>0(n^2logn),论stl依赖症的危害性...TLE到死*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn=4000+5;

int a[maxn],b[maxn],c[maxn],d[maxn],sum[maxn*maxn];

int main()
{
	//freopen("test","r",stdin);
	int kase;
	~scanf("%d",&kase);
	while(kase--){
		int n;
		~scanf("%d",&n);
		for(int i=0;i<n;++i) ~scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
		int cnt=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				sum[cnt++]=a[i]+b[j];
		sort(sum,sum+cnt);
		//cout<<upper_bound(sum,sum+cnt,12)-sum<<" "<<lower_bound(sum,sum+cnt,12)-sum;
		LL ans=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			ans+=upper_bound(sum,sum+cnt,-c[i]-d[j])-lower_bound(sum,sum+cnt,-c[i]-d[j]);
		printf("%lld\n",ans);
		if(kase) puts("");
	}
	return 0;
}
