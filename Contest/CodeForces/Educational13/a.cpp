#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	LL n,k;
	cin >> n >> k;
	LL l = 0,r = 0x3f3f3f3f,res;
	while(l <= r)
	{
		LL m = (l+r)>>1;
		if(m*k > n)
		{
			r =  m-1;
			res = m;
		}
		else l = m+1;
	}
	cout << res*k << '\n';
	return 0;
}

