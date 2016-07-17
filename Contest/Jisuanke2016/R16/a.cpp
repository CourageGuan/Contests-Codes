#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
char s[maxn];
int len;

bool yes()
{
	len = strlen(s);
	int in = 0;
	for(int i=0;i<len;++i)
	{
		if(!in && s[i] != '\"' && s[i] != '\'') return false;
		if(!in)
		{
			if(s[i] == '\"') in = 1;
			if(s[i] == '\'') in = 1;
		}
		if(in == 1 && s[i] == '\'') return false;
		if(in == 2 && s[i] == '\"') return false;
		if(s[i++] == '\\' )
		{
			if(i >= len) return false;
			if(s[i] != '\"' && s[i] != '\'') return false;
		}
	}
	return true;
}

int main()
{
	while(scanf("%s",s) == 1)
	{
		puts(yes()?"Yes":"No");
	}
	return 0;
}
