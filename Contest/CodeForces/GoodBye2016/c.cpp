#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int INF = 0x3f3f3f3f;
int n,p;
int c,d;

void solve()
{
	scanf("%d",&n);
	int l=-INF,r=INF,add =  0;
	F(i,1,n)
	{
		scanf("%d %d",&c,&d);
		if(d == 1)
		{
			l = max(l,1900 - add);
		}
		else
		{
			r = min(r,1899 - add);
		}
		add += c;
	}
	if(l > r)
	{
		puts("Impossible");
		return;
	}
	if( r == INF)
	{
		puts("Infinity");
		return ;
	}
	printf("%d\n",r+add);
}

int main()
{
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}
