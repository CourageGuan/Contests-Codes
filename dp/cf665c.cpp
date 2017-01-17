#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
const int maxn = 2e5 + 10;
char s[maxn];

char get(char a,char b)
{
	char r = 'a';
	while(r == a || r == b) ++r;
	return r;
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%s",s);
	int n = strlen(s),l = 0,cnt;
	F(i,1,n)
	{
		if(i == n || s[i] != s[i-1])
		{
			for(int j=l+1;j<=i-1;j+=2)
			{
				char r = get(s[j-1],s[j+1]);
				s[j] = r;
			}
			l = i;
		}
	}
	puts(s);
	return 0;
}
