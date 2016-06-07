#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n; 
	int mn = 0,mx = 0;
	for(int i=1;i<=n;++i)
	{
		int t;
		cin >> t;
		if(t == 1) mn = i;
		if(t == n) mx = i;
	}
	cout << max(max(mn-1,n-mn),max(mx-1,n-mx)) << '\n';
	return 0;
}
