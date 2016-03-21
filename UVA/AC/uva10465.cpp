//完全背包以及找到剩余部分
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=10000 + 10;
int d[maxn];

int main()
{
	//freopen("test","r",stdin);
	int m,n,t;
	while(scanf("%d %d %d",&m,&n,&t)==3){
		int a,b;
		a=min(m,n);
		b=max(m,n);
		memset(d,0x8f,sizeof(d));
		d[0]=0;
		for(int j=a;j<=t;++j) d[j]=max(d[j],d[j-a]+1);
		for(int j=b;j<=t;++j) d[j]=max(d[j],d[j-b]+1);
		int ans=0;
		for(int i=t;i>0;--i) if(d[i]>0){
			ans=i;	
			break;
		}
		printf("%d",d[ans]);
		if(t-ans>0) printf(" %d",t-ans);
		puts("");
	}
	return 0;
}
