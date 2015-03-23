//01背包 f[i] 表示0-i的最大装载量
//有一个求符合题意位置的技巧：
//	初始化 f 一个极小值，然后 i-1到0比较，第一个最大值则为所求
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define max(a,b) (a>b)?a:b;
const int INF=0x3f3f3f3f;
const int maxn=50*180+10;

int main()
{
	//freopen("test","r",stdin);
	int pos,T,n,t,f[maxn],w[100];
	scanf("%d",&T);
	for(int kase=1;kase<=T;++kase){
		scanf("%d %d",&n,&t);
		memset(f,0x8f,sizeof(f));
		//for(int i=1;i<maxn;++i) f[i]=-INF;
		f[0]=0;
		for(int i=0;i<n;++i) scanf("%d",&w[i]);
		for(int i=0;i<n;++i)
			for(int j=t-1;j>=w[i];--j)
				f[j]=max(f[j],f[j-w[i]]+1);
		for(int i=pos=t-1;i>=0;--i) if(f[i]>f[pos]) pos=i;
		//cout<<pos<<endl;
		printf("Case %d: %d %d\n",kase,f[pos]+1,678+pos);
	}
	return 0;
}
