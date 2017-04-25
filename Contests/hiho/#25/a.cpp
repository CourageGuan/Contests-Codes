#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 3010;
int n,cnt[maxn],d[maxn],p[maxn],tot;

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	F(i,1,n-1)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	tot = 0;
	F(i,1,n) if(cnt[i])
		p[tot++] = cnt[i];
    F(i,1,n) d[i] = maxn;
	d[1] = 0;
	F(i,0,tot-1)
	{
		for(int j=n;j>p[i];--j)
		{
			d[j] = min(d[j],d[j-p[i]]+1);
		}
	}
	F(i,1,n) printf("%d ",d[i]<maxn?d[i]:-1);
	return 0;
}

