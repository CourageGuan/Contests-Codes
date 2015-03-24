//完全背包　递推
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

typedef long long ll;
const int maxn=30000 + 5;
const int w[]={1,5,10,25,50};
ll d[maxn];

void init()
{
	memset(d,0,sizeof(d));
	d[0]=1;
	for(int i=0;i<5;++i)
		for(int j=w[i];j<=maxn-5;++j)
			d[j]+=d[j-w[i]];

}


int main()
{
	//freopen("test","r",stdin);
	init();
	int c;
	while(scanf("%d",&c)==1){
		//if(c==0) continue;
		if(d[c]==1)
			printf("There is only 1 way to produce %d cents change.\n",c);
		else printf("There are %lld ways to produce %d cents change.\n",d[c],c);
	}
	return 0;
}
