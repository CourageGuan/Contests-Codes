#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;

int n,k,a,b,q;
LL cur[maxn];
LL bit[2][maxn];

inline int lowbit(int x)
{
	return x&-x;
}

void add(int id,int x,LL p)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		bit[id][i] += p;
	}
}

LL query(int id,int x)
{
	LL res = 0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		res += bit[id][i];
	}
	return res;
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d %d",&n,&k,&a,&b,&q);
	memset(bit,0,sizeof bit);
	memset(cur,0,sizeof cur);
	for(int i=0;i<q;++i)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int dd,aa;
			scanf("%d %d",&dd,&aa);
			if(a > cur[dd]) add(0,dd,min((LL)aa,a-cur[dd]));
			if(b > cur[dd]) add(1,dd,min((LL)aa,b-cur[dd]));
			cur[dd] += aa;
		}
		else
		{
			int p;
			scanf("%d",&p);
			printf("%lld\n",query(1,p-1)+query(0,n)-query(0,p+k-1));
		}
	}
	return 0;
}

