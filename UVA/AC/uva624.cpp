//01背包及解的打印
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=10000+10;
int f[maxn];
int d[maxn],v[25];


void print_ans(int d[],int C)
{
	while(C){
		printf("%d ",v[d[C]]);
		C-=v[d[C]];
	}
}

int main()
{
	//freopen("test","r",stdin);
	int c,n;
	while(scanf("%d %d",&c,&n)==2){
		int c1=0;
		for(int i=0;i<n;++i){
			scanf("%d",&v[i]);
			c1+=v[i];
		}
		c=min(c1,c);
		memset(d,0x8f,sizeof(d));
		d[0]=0;
		for(int i=n-1;i>=0;--i)
			for(int j=c;j>=v[i];--j)
				if(d[j]<d[j-v[i]]+v[i])
				d[j]=d[j-v[i]]+v[i],f[j]=i;
		int ans=c;
		for(int i=c-1;i>=0;--i) if(d[i]>d[ans]) ans=i;
		print_ans(f,ans);
		//printf("%d %d\n",ans,d[ans]);
		/*int l=(1<<d[ans])-1,r=(1<<n)-1;
		int sum=deal(ans,l,r);
		int cnt=0;
		while(sum){
			if(sum&1) printf("%d ",v[cnt]);
			sum=sum>>1;
			++cnt;
		}*/
		printf("sum:%d\n",d[ans]);
	}
	return 0;
}


