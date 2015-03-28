//01背包
//位置诡异错误...
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxc=10000 + 5;
int d[maxc];
int w[105],v[105];

int main()
{
	//freopen("test","r",stdin);
	int c,n;
	while(scanf("%d %d",&c,&n)==2){
		for(int i=0;i<n;++i)
			scanf("%d %d",&w[i],&v[i]);
		int t=0;
		if(c+200>2000) t=200;
		memset(d,0,sizeof(d));
		for(int i=0;i<n;++i)
			for(int j=c+t;j>=w[i];--j)
					d[j]=max(d[j],d[j-w[i]]+v[i]);
		int pos=c+t;
		for(int i=c+t;i>=0;--i)
			if(d[i]>d[pos] && (i>2000 || i<=c)) pos=i;
		printf("%d\n",d[pos]);
	}
	return 0;
}

