#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int x[] = {500,1000,1500,2000,2500};
const int mn[] = {150,300,450,600,750};
int m[5],w[5],h[2];

int main()
{
	//freopen("test.txt","r",stdin);
	LL ans = 0;
	for(int i=0;i<5;++i) scanf("%d",m+i);
	for(int i=0;i<5;++i) scanf("%d",w+i);
	for(int i=0;i<2;++i) scanf("%d",h+i);
	for(int i=0;i<5;++i)
	{
		ans += max(mn[i],x[i]-x[i]*m[i]/250-50*w[i]);
	}
	ans += h[0]*100;
	ans -= h[1]*50;
	printf("%lld\n",ans);
	return 0;
}
