#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
//	freopen("test.txt"."r",stdin);
	int n,m;
	cin >> n >> m;
	int cur = 1,emp = 1;
	while(n--)
	{
		//cur = (1LL*2*m*cur - (cur - emp))%mod;
		cur = (1LL*(2*m-1)*cur%mod + emp) %mod;
		emp = 1LL*emp*m%mod;
	}
	cout << cur ;
	return 0;
}
