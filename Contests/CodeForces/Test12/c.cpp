#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
LL d[12][maxn];
int n;

inline int lowbit(int x)
{
	return x&-x;
}

void add(int k,int p,LL val)
{
	for(int i=p;i<=n;i+=lowbit(i))
	{
		d[k][i] += val;
	}
}

LL query(int k,int R)
{
	LL res = 0;
	for(int i=R;i>0;i-=lowbit(i))
	{
		res += d[k][i];
	}
	return res;
}


int main()
{
	//freopen("test.txt","r",stdin);
	int k;
	scanf("%d %d",&n,&k);
	memset(d,0,sizeof d);
	for(int i=0;i<n;++i)
	{
		int a; scanf("%d",&a);
		add(1,a,1);
		for(int i=2;i<=k+1;++i)
		{
			LL cur = query(i-1,a-1);
			add(i,a,cur);
		}
	}
	printf("%lld\n",query(k+1,n));
	return 0;
}
