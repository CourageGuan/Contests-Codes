#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10 ;
char s[maxn];

int cnt[255];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s",s);
	int n = strlen(s);
	memset(cnt,0,sizeof cnt);

	for(int i=0;i<n;++i) ++cnt[s[i]];

	for(int i=25;i>=0;--i)
	{
		if(cnt[i+'a']&1)
		{
			bool vis = false;
			for(int j=0;j<26;++j)
			{
				if(j != i && cnt[j+'a']&1)
				{
					++cnt[j+'a'];
					vis = true;
					break;
				}
			}
			if(vis) --cnt[i+'a'];
		}
	}

	char mid = 'A';
	for(char i='a';i<='z';++i)
	{
		if(cnt[i]&1)
		{
			mid = i;
		}
		for(int t=0;t<cnt[i]/2;++t) putchar(i);
	}
	if(mid != 'A') putchar(mid);
	for(char i='z';i>='a';--i)
	{
		for(int t=0;t<cnt[i]/2;++t) putchar(i);
	}
	puts("");
	return 0;
}
