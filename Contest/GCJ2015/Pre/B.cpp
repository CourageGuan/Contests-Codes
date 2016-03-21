//构造题...
//首先不再继续分然后吃消耗的时间是当前最高度，答案肯定是小于等于最开始的最大高度的。
//枚举的是每一块最终被分为小于等于某高度，然后结果是 次数+此高度 ，取一个最小值。
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=1000;
int a[maxn];

int main()
{
	freopen("B-large-practice.in","r",stdin);
	freopen("b.out","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=0;i<n;++i){
			scanf("%d",a+i);
			ans=max(ans,a[i]);
		}
		int res=ans;
		while(res>1){
			int sum=0;
			for(int i=0;i<n;++i) sum+=(a[i]-1)/res;
			ans=min(ans,sum+res);
			--res;
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
	return 0;
}

