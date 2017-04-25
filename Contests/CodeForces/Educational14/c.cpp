#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e6 + 10;
char s[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s",s+1);
	int n = strlen(s+1); 
	int pre = 0,po = 0,lst = 0;
	for(int i=1;i<=n;++i)
	{
		if(!pre && s[i] != '0' && s[i] != '.') pre = i;
		if(s[i] == '.') po = i;
	}
	if(po == 0)
	{
		po = n+1;
		s[po] = '.';
		s[po+1] = '\0';
		n = po;
	}
	for(int i=n;i>=1;--i)
	{
		if(s[i] != '0' && s[i] != '.')
		{
			lst = i;
			break;
		}
	}
	if(po - pre >= 1)
	{
		if(!pre)
		{
			putchar('0');
			return 0;
		}
		putchar(s[pre]);
		if(lst > pre) putchar('.');
		for(int i=pre+1;i<=lst;++i)
		{
			if(i == po) continue;
			putchar(s[i]);
		}
		if(po - pre - 1) printf("E%d",po-pre-1);
		puts("");
	}
	else
	{
		if(!pre)
		{
			putchar('0');
			return 0;
		}
		putchar(s[pre]);
		if(lst > pre) putchar('.');
		for(int i=pre+1;i<=lst;++i) putchar(s[i]);
		printf("E%d",po - pre);
		puts("");
	}
	return 0;
}

