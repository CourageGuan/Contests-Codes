#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

#define fi first
#define se second

int n,m,t;

const int mod = 1e8 + 7;
const int maxn = 1e4;
typedef long long LL;

bool isprm[maxn+10];
int prm[maxn];
int pn;
vector<pair<int,int> > p;

void GetPrm(int n) 
{
    memset(isprm,0,sizeof(isprm));
    isprm[1] = 1;
    pn = 0;
    for(LL i = 2;i <= n;++i)
        if(!isprm[i])
        {
            prm[pn++] = i;
            for(LL j = i*i;j <= n;j += i) isprm[j] = 1;
        }
}

void fact(int n)
{
	for(int i=0;i<pn;++i)
	{
		if(n%prm[i] == 0)
		{
			int cnt = 0;
			while(n % prm[i] == 0)
			{
				n /= prm[i];
				++cnt;
			}
			p.push_back(make_pair(prm[i],cnt));
		}
		if(n == 1) break;
	}
	if(n != 1) p.push_back(make_pair(n,1));
}

int main()
{
	//freopen("input.txt","r",stdin);
	GetPrm(maxn);
	int z = 0;
	while(~scanf("%d %d %d",&n,&m,&t))
	{
		if(n == 0 && m == 0 && t == 0) break;
		p.clear();
		fact(n);
		int tot = p.size();
		LL ans = 0;

		for(int i=1;i<(1<<tot);++i)
		{
			LL cur = 1;
			for(int j=0;j<tot;++j)
			{
				int  tt;
				tt = (p[j].se*m)/t - (p[j].se*m)/(t+1);

				if(i&(1<<j))
					cur = cur*tt %mod;
				else 
					cur = cur*(p[j].se*m/(t+1) + 1)%mod;
			}

			ans += cur;
			if(ans >= mod) ans -= mod;
		}
		printf("Case %d: %lld\n",++z,ans);
	}
	return 0;
}
