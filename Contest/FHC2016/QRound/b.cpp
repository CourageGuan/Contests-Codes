#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n;
char s[2][maxn];

int solve()
{
	int res = 0,i;
	for(int z=0;z<2;++z)
	{
		i = 0;
		while(i < n)
		{
			if(s[z][i] == '.')
			{
				++res;
				while(i < n && s[z][i] == '.') ++i;
			}
			++i;
		}
	}
	int flag = 1;
	i = 0;
	while(i<n)
	{
		if(i && s[1][i] == '.' && s[1][i-1] == 'X') flag = 1;
		if(s[0][i] == '.')
		{
			int len = 0;
			while(i+len<n && s[0][i+len] == '.')
			{
				if(i+len && s[1][i+len] == '.' && s[1][i+len-1] == 'X') flag = 1;
				++len;
			}
			if(len == 1)
			{
				if(s[1][i] == '.' && flag)
				{
					--flag;
					--res;
				}
			}
			i += len;
		}
		++i;
	}
	i = 0;
	flag = 1;
	while(i<n)
	{
		if(i && s[0][i] == '.' && s[0][i-1] == 'X') flag = 1;
		if(s[1][i] == '.')
		{
			int len = 0;
			while(i+len<n && s[1][i+len] == '.')
			{
				if(i+len && s[0][i+len] == '.' && s[0][i+len-1] == 'X') flag = 1;
				++len;
			}
			if(len == 1)
			{
				if(s[0][i] == '.' && !((!i || s[0][i-1] == 'X') && (i==n-1 || s[0][i+1] == 'X')) && flag)
				{
				//	printf("%d\n",i);
					--flag;
					--res;
				}
			}
			i += len;
		}
		++i;
	}
	return res;
}

int main()
{
//	freopen("test.txt","r",stdin);
	freopen("high_security.txt","r",stdin);
	freopen("ans_b.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		scanf("%s %s",s[0],s[1]);
		printf("Case #%d: %d\n",z,solve());
	}
	return 0;
}

