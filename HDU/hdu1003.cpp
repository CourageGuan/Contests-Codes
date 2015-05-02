//最大连续子序列
#include<stdio.h>
#include<iostream>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=100010;
int save[maxn];

int main()
{
	int T,n,kase=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int last=0,ans=-INF,p1,p2;
		for(int i=0;i<n;++i){
		   	scanf("%d",&save[i]);
			last=max(last,0)+save[i];
			if(last>ans){
				p2=i;
				ans=last;
			}
		}
		int sum=0;
		for(int i=p2;i>=0;--i){
			sum+=save[i];
			if(sum==ans){
				p1=i;
				break;
			}
		}
		if(kase) puts("");
		printf("Case %d:\n",++kase);
		printf("%d %d %d\n",ans,p1+1,p2+1);
	}
	return 0;
}


