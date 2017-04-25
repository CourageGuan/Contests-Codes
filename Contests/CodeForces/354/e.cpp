#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e6 + 10;
int a[maxn];
const int INF = 0x3f3f3f3f;
int n,k,cnt;

bool yes()
{
	if(k == 0)
	{
		if(a[0] == 0)
			return true;
		if(a[0] == INF && (n+1-cnt)&1)
			return true;
		return false;
	}
	else
	{
		if(!cnt)
		{
			for(int j=0;j<10;++j)
			{
				LL cur = 0,mod = rand()%(LL)5e5 + (LL)5e5;
				for(int i=n;i>=0;--i)
					cur = (cur*k + a[i])%mod;
//				printf("%d\n",cur);
				if(cur != 0) return false;
			}
			return true;
		}
		else
		{
			return n&1;
		}
	}
	return true;
}

int main()
{
	cin >> n >> k;
	for(int i=0;i<=n;++i)
	{
		char s[100];
		scanf("%s",s);
		if(s[0] == '?') a[i] = INF,++cnt;
		else
		{
			int len = strlen(s);
			int cur = 0;
			for(int i=(s[0]=='-');i<len;++i)
			{
				cur = cur*10 + s[i]-'0';
			}
			a[i] = cur*(s[0]=='-'?-1:1);
		}
	}
	puts(yes()?"Yes":"No");
	return 0;
}
