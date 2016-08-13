#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
int n,k;
int mark[100];
LL p[100];

int main()
{
	//freopen("test.txt","r",stdin);
	p[0] = 1;
	for(int i=1;i<62;++i) p[i] = p[i-1]*2;
	cin >> T;
	for(int z=1;z<=T;++z)
	{
		printf("Case #%d:\n",z);
		memset(mark,0,sizeof mark);

		cin >> n >> k;
		LL t = ((1LL<<k) - 1 - n + !(n&1))/2;
//		printf("%lld\n",t);
		while(t)
		{
			for(int j=k-1;j>=0;--j)
			{
				if(t >= p[j])
				{
					mark[j] = 1;
					t -= p[j];
					break;
				}
			}
		}
		for(int i=0;i<k;++i)
			printf("%lld %c\n",(!(n&1) && i==k-1)?p[i]+1:p[i],mark[i]?'-':'+');
	}
	return 0;
}
