#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n,k,len;
char s[maxn];

int solve(char c)
{
	int l = 0,r = 0;
	int res = 0,cnt = 0;
	while(l < n && r < n)
	{
		while(r < n && (cnt < k || s[r] != c))
		{
			if(s[r] == c) ++cnt;
			++r;
		}
		res = max(res,r-l);
		while(l < n && s[l] != c) ++l;
		++l; --cnt;
	}
	return res;
}

int main()
{
	cin >> n >> k;
	cin >> s;
	cout << max(solve('a'),solve('b')) << '\n';
	return 0;
}
