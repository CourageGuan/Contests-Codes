#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;

struct S{
	char c;
	LL l;
	bool operator==(const S& rhs) const
	{
		return c == rhs.c && l == rhs.l;
	}
	bool operator>=(const S& rhs) const
	{
		return c == rhs.c && l >= rhs.l;
	}
} t[maxn],s[maxn];

int n,m;
int f[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i) scanf("%lld-%c",&t[i].l,&t[i].c);
	for(int i=0;i<m;++i) scanf("%lld-%c",&s[i].l,&s[i].c);
	int cnt = 0;
	for(int i=0;i<n;++i)
	{
		t[cnt].c = t[i].c;
		t[cnt].l = t[i].l;
		while(i+1 < n && t[cnt].c == t[i+1].c)
		{
			t[cnt].l += t[i+1].l;
			++i;
		}
		++cnt;
	}
	n = cnt;
	cnt = 0;
	for(int i=0;i<m;++i)
	{
		s[cnt].c = s[i].c;
		s[cnt].l = s[i].l;
		while(i+1 < m && s[cnt].c == s[i+1].c)
		{
			s[cnt].l += s[i+1].l;
			++i;
		}
		++cnt;
	}
	m = cnt;
	LL res = 0;
	if(m == 1)
	{
		for(int i=0;i<n;++i) if(t[i] >= s[0]) res += t[i].l - s[0].l + 1;
	}
	else if(m == 2)
	{
		for(int i=0;i+1<n;++i) if(t[i] >= s[0] && t[i+1] >= s[1]) ++res;
	}
	else
	{
		f[1] = 0;
		for(int i=2;i<m-1;++i)
		{
			int j = f[i-1];
			while(j && !(s[i] == s[j+1])) j = f[j];
			f[i] = s[j+1] == s[i]?j+1:0;
		}
		int j = 0;
		for(int i=1;i<n-1;++i)
		{
			while(j && !(t[i] == s[j+1])) j = f[j];
			if(t[i] == s[j+1]) ++j;
			if(j == m-2)
			{
				if(t[i-j] >= s[0] && t[i+1] >= s[j+1]) ++res;
				j = f[j];
			}
		}
	}
	printf("%lld\n",res);
	return 0;
}
