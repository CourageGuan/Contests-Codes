//分情况的二分答案
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn=100000 + 5;
int n,r[maxn],lft[maxn],rgt[maxn];

bool ok(int p)
{
	int x=r[1],y=p-r[1];	//以第一个人取值为分界 左边x个 右边y个
	lft[1]=x;rgt[1]=0;
	for(int i=2;i<=n;++i){
		if(i&1) {
			rgt[i]=min(y-rgt[i-1],r[i]);	//尽量向右取
			lft[i]=r[i]-rgt[i];
		}
		else{
			lft[i]=min(x-lft[i-1],r[i]);	//尽量向左取
			rgt[i]=r[i]-lft[i];
		}
	}
	return lft[n]==0;
}


int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d",&n) && n){
		for(int i=1;i<=n;++i) scanf("%d",&r[i]);
		if(n==1){
			printf("%d\n",r[1]);
			continue;
		}
		r[n+1]=r[1];
		int L=0,R=0;
		for(int i=1;i<=n;++i) L=max(L,r[i]+r[i+1]);	
		if(n&1){
			for(int i=1;i<=n;++i) R=max(R,r[i]*3); 
			while(L<R){
				int M=L+(R-L)/2;
				if(ok(M)) R=M;
				else L=M+1;
				//cout<<M<<endl;
			}
		}
		printf("%d\n",L);
	}
	return 0;
}

