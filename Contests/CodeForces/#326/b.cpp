#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
vector<LL> fac;
const double eps = 1e-12;

LL solve(LL n)
{
	fac.clear();
	bool flag = 1;
	for(LL i=2;i*i<=n;++i)
	{
		if(n%i == 0)
		{
		   	fac.push_back(i);
			LL t = (LL)(sqrt(i)+eps);
			if(t*t == i) flag = 0;

		   	fac.push_back(n/i);
			t = (LL)(sqrt(n/i)+eps);
			if(t*t == n/i) flag = 0;

		}
	}
	LL t = (LL)(sqrt(n)+eps);
	if(t*t == n) flag = 0;

	if(flag) return n;
	sort(fac.begin(),fac.end());
	for(int j=fac.size()-1;j>=0;--j)
	{
		LL n = fac[j];
		bool flag = 1;
		for(LL i=2;i*i<=n;++i)
		{
			if(n%i == 0)
			{
				LL t = (LL)(sqrt(i)+eps);
				if(t*t == i)
				{
				   	flag = 0;
					break;
				}
				t = (LL)(sqrt(n/i)+eps);
				if(t*t == n/i)
				{
					flag = 0;
					break;
				}
			}
		}
		LL t = (LL)(sqrt(n)+eps);
		if(t*t == n) flag = 0;
		if (flag) return n;
	}
	return 1;
}

int main()
{
	LL n;
	scanf("%lld",&n);
	printf("%lld\n",solve(n));
	return 0;
}

