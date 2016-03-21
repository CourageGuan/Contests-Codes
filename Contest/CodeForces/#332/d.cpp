#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;

vector<pair<LL,LL> > ans ;

int main()
{
	//freopen("test.txt","r",stdin);
	LL x;
	scanf("%lld",&x);
	ans.clear();
	LL cnt = 0;
	for(LL m=1; ;++m)
	{
		LL n = (x + m*(m*m-1)/6)/(m*(m+1)/2);
		LL res = n*m*(m+1)/2 - m*m*(m-1)/2 + m*(m-1)*(2*m-1)/6;
	//	printf("%lld %lld %lld\n",m,n,res);
		if(m >= n)
		{
			if(m > n)
			{
				cnt *= 2;
			}	
			else
			{
				if(res == x)
				{
					++cnt;
					ans.push_back(make_pair(m,n));
					cnt *= 2;
					cnt -= 1;
				}
				else cnt *= 2;
			}
			break;
		}

		if(res != x) continue;
		++cnt;
		ans.push_back(make_pair(m,n));
	}
	printf("%lld\n",cnt);
	for(int i=0;i<ans.size();++i)
	{
		printf("%lld %lld\n",ans[i].first,ans[i].second);
	}
	for(int i=ans.size()-1;i>=0;--i)
	{
		if(cnt&1 && i == ans.size()-1) continue;
		printf("%lld %lld\n",ans[i].second,ans[i].first);
	}
	return 0;
}
