//完全背包　递推
//细节比较坑
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

typedef long long ll;
const int maxn=30000 + 5;
const int w[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
ll d[maxn];

void init()
{
	memset(d,0,sizeof(d));
	d[0]=1;
	for(int i=0;i<11;++i)
		for(int j=w[i];j<=maxn-5;++j)
			d[j]+=d[j-w[i]];

}


int main()
{
	//freopen("test","r",stdin);
	init();
	float t;
	while(scanf("%f",&t)){ 
		int c=(t+0.005)*100;
		if(c==0) break;
		printf("%6.2f%17lld\n",t,d[c]);
	}
	return 0;
}

