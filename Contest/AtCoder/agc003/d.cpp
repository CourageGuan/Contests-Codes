#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
 
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
 
const LL INF = 1e10 + 7;
 
int n,tot;
map<LL,int> cnt;
map<LL,LL> cp;
LL p[4][3000];
 
void init()
{
	tot = 0;
	for(int i=2;;++i)
	{
		if(1LL*i*i*i >= INF) break;
		if(p[0][i]) continue;
		p[1][tot] = i;
		p[2][tot] = i*i;
		p[3][tot++] = 1LL*i*i*i;
		for(int j=i;;j+=i)
		{
			if(1LL*j*j*j >= INF) break;
			p[0][j] = 1;
		}
	}
}
 
int main()
{
	//freopen("test.txt","r",stdin);
	init();
	scanf("%d",&n);	
	int ans = 0,fi = 1;
	R(i,n)
	{
		LL s,x,y;
		scanf("%lld",&s);
 
		x = y = 1;
		R(j,tot)
		{
			while(s%p[3][j] == 0)
			{
				s /= p[3][j];
			}
			if(s%p[2][j] == 0)
			{
				x *= p[2][j];
				y *= p[1][j];
				if(y > INF) y = INF;
			}
			else if(s%p[1][j] == 0)
			{
				x *= p[1][j];
				y *= p[2][j];
				if(y > INF) y = INF;
			}
		}
		s /= x;
		if(s != 1)
		{
			int t = sqrt(s),r = -1;
			F(j,max(1,t-1),t+1)
				if(1LL*j*j == s)
				{
					r = j;
					break;
				}
			if(r != -1)
			{
				if(y < INF) y *= r;
			}
			else
			{
				if(INF/s/s < y) y = INF;
				else y *= 1LL*s*s;
			}
		}
		if(y >= INF)
		{
			++ans;
			continue;
		}
 
		s *= x;
 
		if(s == 1)
		{
			if(fi)
			{
				fi = 0;
				++ans;
			}
			continue;
		}
 
		cnt[s]++;
		cp[s] = y;
	}
	for(auto it = cnt.begin();it != cnt.end(); ++it)
	{
		LL gf = cp[it->fi];
		if(it->fi < gf || cnt.find(gf) == cnt.end()) ans += max(it -> se,cnt[gf]);
	}
	printf("%d\n",ans);
	return 0;
}
