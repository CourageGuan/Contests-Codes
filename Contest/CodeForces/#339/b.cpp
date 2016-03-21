#include<bits/stdc++.h>
using namespace std;

const int maxn = 100100;
char s[maxn],ans[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	ans[0] = '1'; 
	int len = 0,flag = 0;
	for(int i=0;i<n;++i)
	{
		scanf("%s",s);
		if(len == -1) continue;
		if(s[0] == '0') len = -1;
		if(s[0] == '1')
		{
			int cur = 0;
			for(int i=1;i<strlen(s);++i)
			{
				++cur;
				if(s[i] != '0')
				{
					strcpy(ans,s);
					cur = 0;
					break;
				}
			}
			len += cur;
		}
		else strcpy(ans,s);
	}
	if(len == -1) puts("0");
	else
	{
		printf("%s",ans);
		for(int i=0;i<len;++i) putchar('0');
		puts("");
	}
	return 0;
}
