//楼教主男人八题，O(nv∑logmi)仍有可能TLE...
//主要学习O(nv)的多重背包算法
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int maxn=110,maxm=100010;
const int INF=0x3f3f3f3f;
int a[maxn],c[maxn],sum[maxm];
bool d[maxm];

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m) && n+m){
		for(int i=0;i<n;++i) scanf("%d",a+i);
		for(int i=0;i<n;++i) scanf("%d",c+i);
		/*memset(d,0,sizeof d);	
		d[0]=1;
		for(int i=0;i<n;++i){
			if(a[i]*c[i]>=m){
				for(int j=a[i];j<=m;++j)
					d[j]|=d[j-a[i]];
				continue;
			}
			int k=1;
			while(k<c[i]){
				for(int j=m;j>=k*a[i];--j)
					d[j]|=d[j-k*a[i]];
				c[i]-=k;
				k*=2;
			}
			k=c[i];
			for(int j=m;j>=k*a[i];--j)
				d[j]|=d[j-k*a[i]];
		}
		int ans=0;
		for(int i=1;i<=m;++i) if(d[i]) ++ans;
		printf("%d\n",ans);
		*/
		int ans=0;
		memset(d,0,sizeof(d));
		d[0]=1;
		for(int i=0;i<n;++i){
			memset(sum,0,sizeof sum);	//限定出现次数
			for(int j=a[i];j<=m;++j){	
				if(!d[j] && d[j-a[i]]  && sum[j-a[i]]<c[i]){	//当前位置没有出现，且上个位置出现了，且还有剩余次数
					d[j]=1;
					sum[j]=sum[j-a[i]]+1;
					++ans;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

