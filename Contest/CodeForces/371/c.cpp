#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define R(i,n) for(int i=0;i<(n);++i)
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fill(a,b) memset(a,b,sizeof(a))

map<LL,int> mp;

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	R(i,n)
	{
		char op[2];
		LL d,x = 0;
		int j=0;
		scanf("%s %lld",op,&d);
		while(d)
		{
			x |= (d&1)<<j;
			d /= 10;
			++j;
		}
		if(op[0] == '+')
		{
			mp[x]++;
		}
		else if(op[0] == '-')
		{
			mp[x]--;
		}
		else
		{
			printf("%d\n",mp[x]);
		}
	}
	return 0;
}
