#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

char s[110];
int n;

void solve()
{
	scanf("%d %s",&n,s+1);
	if(n < 3)
	{
		puts(s+1);
		return;
	}
	string ans = "";
	for(int i=1;i<=n;)
	{
		if(s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o')
		{
			ans += "***";
			i += 3;
			while(i + 1 <= n && s[i] == 'g' && s[i+1] == 'o') i += 2;
		}
		else
		{
		   	ans += s[i];
			++i;
		}
	}
	puts(ans.c_str());
}

int main()
{
//	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
