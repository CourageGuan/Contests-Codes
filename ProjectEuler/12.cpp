#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL solve()
{
	LL sum = 1;
	for(int i=2;;++i)
	{
		sum += i;
		LL t = 1;
		int cnt = 0;
		while(t*t <= sum)
		{
			if(sum%t == 0) cnt +=2;
			if(t*t == sum) --cnt;
			++t;
		}
		if(cnt > 500) return sum;
	}
	return -1;
}

int main()
{
	printf("%lld\n",solve());
	return 0;
}
