#include<bits/stdc++.h>
using namespace std;

const int maxn = 200;
char s[maxn];

int a,b,d;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> s;
	int len = strlen(s);
	int po,e;
	for(int i=0;i<len;++i)
	{
		if(s[i] == '.') po = i;
		if(s[i] == 'e') e = i;
	}
	b = atoi(s + e + 1);
	if(e - po == 2 && s[e-1] == '0')
	{
		if(s[0] == '0')
		{
			puts("0");
			return 0;
		}
		for(int i=0;i<po;++i)
		{
			putchar(s[i]);
		}
		for(int i=0;i<b;++i) putchar('0');
		puts("");
	}
	else
	{
		int pos = 0;
		for(int i=0;i<e;++i)
		{
			if(s[i] == '.') continue;
			putchar(s[i]);
			if(pos == b && i != e-1) putchar('.');
			++pos;
		}
		for(int i=pos;i<=b;++i) putchar('0');
		puts("");
	}
	return 0;
}
