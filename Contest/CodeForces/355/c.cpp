#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1e9+7;
const int maxn = 1e5 + 10;
int mark[256];
int cnt[64];
char s[maxn];

void init()
{
	for(int i=0;i<10;++i)
		mark['0'+i] = i;
	for(int i=0;i<26;++i)
	{
		mark['A'+i] = 10+i;
		mark['a'+i] = 36+i;
	}
	mark['-'] = 62;
	mark['_'] = 63;
	for(int i=0;i<64;++i)
	{
		for(int j=0;j<64;++j)
		{
			++cnt[i&j];
		}
	}
}



int main()
{
	//freopen("test.txt","r",stdin);
	init();
	scanf("%s",s);	
	int len = strlen(s);
	LL ans = 1;
	for(int i=0;i<len;++i)
	{
		ans = ans*cnt[mark[s[i]]]%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
