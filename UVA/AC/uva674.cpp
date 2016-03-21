//uva 此类问题泛滥...
#include<cstdio>
#include<cstring>

typedef long long ll;
const int maxn=10000;
ll d[maxn];

const int w[]={1,5,10,25,50};
int n;

void solve()
{
	memset(d,0,sizeof(d));
	d[0]=1;
	for(int i=0;i<5;++i)
		for(int j=w[i];j<8000;++j)
			d[j]+=d[j-w[i]];
}

int main()
{
	solve();
	while(scanf("%d",&n)==1)
		printf("%lld\n",d[n]);
	return 0;
}
