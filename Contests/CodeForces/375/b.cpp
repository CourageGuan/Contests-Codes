#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 300;

char s[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	scanf("%d %s",&n,s);
	int a,b,cur,in;
	a = b = cur = in = 0;
	F(i,0,n-1)
	{
		if(s[i] == '(')
		{
			a = max(a,cur);
			cur = 0;
			in = 1;
			continue;
		}
		if(s[i] == ')')
		{
			if(cur) ++b;
			cur = 0;
			in = 0;
			continue;
		}
		if(in)
		{
			if(s[i] == '_')
			{
				if(cur) ++b;
				cur = 0;
			}
			else ++cur;
		}
		else
		{
			if(s[i] == '_')
			{
				a = max(a,cur);
				cur = 0;
			}
			else ++cur;
		}
	}
	if(cur) a = max(a,cur);
	printf("%d %d\n",a,b);
	return 0;
}
