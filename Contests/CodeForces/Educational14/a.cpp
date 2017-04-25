#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	int cnt = 0;
	for(int i=0;i<n;++i)
	{
		int a;
		cin >> a;
		if(a) ++cnt;
	}
	if(n == 1)
		puts(cnt == n?"YES":"NO");
	else
		puts(cnt==n-1?"YES":"NO");
	return 0;
}
