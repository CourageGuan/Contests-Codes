#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

int n,k;

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&k);
	int t = 240-k,ans = n,cnt = 0;
	F(i,1,10)
	{
		if(t >= 5*i)
		{
			t -= 5*i;
			++cnt;
		}
		else break;
	}
	ans = min(ans,cnt);
	printf("%d\n",ans);
	return 0;
}
