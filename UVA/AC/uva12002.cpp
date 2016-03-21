//LIS/LDS变种
//记录的是n-i的最长上升，下降，不降(从第一次上升开始)，不升(从第一次下降开始)序列...
//答案是从i开始的上升+不升(单次) 或　下降+不降(单次) 的最大值-1
#include<stdio.h>
#include<iostream>
using namespace std;

const int maxn=500 + 10;
int n,a[maxn],upp[maxn],dop[maxn],upd[maxn],dod[maxn];

int solve()
{
	for(int i=n-1;i>=0;--i){
		upd[i]=dod[i]=upp[i]=dop[i]=1;
		for(int j=n-1;j>i;--j){
			if(a[i]>=a[j]) upp[i]=max(upp[i],upp[j]+1);
			if(a[i]<a[j]) dop[i]=max(dop[i],dod[j]+1);
			if(a[i]>a[j]) upd[i]=max(upd[i],upp[j]+1);
			if(a[i]<=a[j]) dod[i]=max(dod[i],dod[j]+1);
		}
	}
	//for(int i=0;i<n;++i) cout<<upp[i]<<" "<<dop[i]<<endl;
	int mx=0;
	for(int i=0;i<n;++i){
		mx=max(mx,upp[i]+dop[i]-1);
		mx=max(mx,upd[i]+dod[i]-1);
	}

	return mx;
}

int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		printf("%d\n",solve());
	}
	return 0;
}

