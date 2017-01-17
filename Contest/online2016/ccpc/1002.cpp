#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int mod = 1e9 + 7;
const int maxn = 350;
int vis[2010],n;
LL a[maxn];
vector<int> primes;

template<size_t sz> struct bitset_comparer {
	bool operator() (const bitset<maxn> &b1, const bitset<maxn> &b2) const {
		return b1.to_ulong() < b2.to_ulong();
	}
};

map<bitset<maxn>,LL,bitset_comparer> d;
map<bitset<maxn>,LL,bitset_comparer>::iterator it;

void init()
{
	F(i,2,2000)
	{
		if(vis[i]) continue;
		primes.push_back(i);
		for(int j=i;j<2000;j+=i) vis[j] = 1;
	}
}

int solve()
{
	R(i,n)
	{
		LL t = a[i];
		string s = "";
		R(j,primes.size())
		{
			int cnt = 0;
			while(t%primes[j] == 0)
			{
				t /= primes[j];
				++cnt;
			}
			s += cnt&1?"1":"0";
		}
		bitset<maxn> b(s);
		for(it = d.begin();it != d.end();++it)
		{
			t = d[(it -> first) ^ b];
			t++;
			if(t > mod) t -= mod;
			d[(it -> first) ^ b] = t;
		}
		t = d[b];
		t++;
		if(t > mod) t -= mod;
		d[b] = t;
		printf("%d\n",d[b]);
	}
	bitset<maxn> b; b.reset();
	return d[b];
}

int main()
{
	freopen("test.txt","r",stdin);
	init();
	int T;
	scanf("%d",&T);
	R(z,T)
	{
		d.clear();
		scanf("%d",&n);
		R(i,n) scanf("%lld",a+i);
		printf("Case #%d:\n",z);
		printf("%d\n",solve());
	}
	return 0;
}
