#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n,m;

int main()
{
//	freopen("test.txt","r",stdin);
	cin >> m >> n;
	int res = 0,cur = 0;
	for(int i=0;i<n;++i)
	{
		char s[maxn];
		scanf("%s",s);
		bool yes = 0;
		for(int i=0;i<m;++i) if(s[i] == '0')
		{
			yes = 1;
			break;
		}
		if(yes) ++cur;
		else cur = 0;
		res = max(cur,res);
	}
	cout << res;
	return 0;
}
