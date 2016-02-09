#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int lens,lent;
char s[maxn],t[33];

int solve()
{
	int res = 0;
	for(int i=0;i<lens-lent+1;++i)
	{
		int j = 0;
		while(j < lent && s[j+i] == t[j]) ++j;
		if(j == lent)
		{ 
			s[j+i-1] = '#';
			++res;
		}
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s %s",s,t);	
	lens = strlen(s),lent = strlen(t);
	printf("%d\n",solve());
	return 0;
}
