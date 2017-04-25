#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxd = 1594323;

LL d[2][maxd][2];
int n,cur,f[1<<13][2],p[maxd],s[1<<26];

void init()
{
	for(int i=0;i<(1<<13);++i)
	{
		for(int j=0;j<13;++j)
			f[i][0] |= ((i>>j)&1)<<(j<<1);
		f[i][1] = f[i][0] << 1;
	}
	for(int i=0;i<maxd;++i)
	{
		int t = i;
		for(int j=12;j>=0;--j)
		{
			p[i] |= (t%3)<<((12-j)<<1);
			t/=3;
		}
		s[p[i]] = i;
	}
}

void print(int x)
{
	for(int i=12;i>=0;--i)
	{
		printf("%d",((x>>(i<<1))&3));
	}
	puts("");
}

int main()
{
	freopen("test.txt","r",stdin);
	init();
	scanf("%d",&n);
	LL ans = 0;
	int fi = f[(1<<13)-1][0],se = f[(1<<13)-1][1];
	for(int z=0;z<n;++z) 
	{
		int x;
		scanf("%d",&x);
		cur^=1;
		memcpy(d[cur],d[cur^1],sizeof (d[0]));
		for(int i = 0;i<maxd;++i)
		{
			if(d[cur^1][i][0])
				d[cur][s[ ((p[i]&fi)^f[x][0] & (((p[i]&se)>>1)^fi) ) | (p[i]&f[x][1]) ]][1] += d[cur^1][i][0];
			if(d[cur^1][i][1])
				d[cur][s[ ((p[i]&fi)^f[x][0] & (((p[i]&se)>>1)^fi) ) | (((p[i]&f[x][1])>>1)^((p[i]&se)>>1)) | (p[i]&f[x][1]) ]][0] += d[cur^1][i][1];
		}
		++d[cur][s[f[x][1]]][1];
	}
	for(int i = 0;i<maxd;++i)
	{
		for(int j=0;j<2;++j)
		{
			if(!d[cur][i][j]) continue;
			bool flag = true;
			int t = i;
			while(t)
			{
				int tt = t%3;
				if(tt == 1 || (tt == 2 && j == 0))
				{
					flag = false;
					break;
				}
				t/=3;
			}
			if(flag)
			{
//				printf("%d %d %lld\n",i,j,d[cur][i][j]);
				ans += d[cur][i][j];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

