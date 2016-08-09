#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))



int main()
{
	//freopen("test.txt","r",stdin);
	LL n,m;
	cin >> n >> m;
	LL res = 0;
	F(i,1,n)
	{
		res += (m + i)/5 - i/5;
	}
	cout << res << '\n';
	return 0;
}
