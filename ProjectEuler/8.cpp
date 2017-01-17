#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


LL solve()
{
	string s,t;
	s = "";
	while(cin>>t) s += t;

	LL res = 0;
	for(int i=0;i+12<s.size();++i)
	{
		LL cur = 1;
		for(int j=i;j<=i+12;++j)
		{
			cur*=s[j] - '0'; 
			if(!cur) break;
		}
		res = max(res,cur);
	}
	return res;
}

int main()
{
	freopen("8.txt","r",stdin);
	printf("%lld\n",solve());
	return 0;
}
