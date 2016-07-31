#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)

map<int,int> mp;

int main()
{
	//freopen("test.txt","r",stdin);
	int fac[33];
	fac[0] = 1;
	F(i,1,31) fac[i] = fac[i-1]*2;
	int n;
	scanf("%d",&n);
	LL cnt = 0;
	R(i,n)
	{
		int a;
		scanf("%d",&a);
		F(i,1,31)
		{
			cnt += mp[fac[i]-a];
		}
		mp[a]++;
	}
	cout << cnt << '\n';
	return 0;
}
