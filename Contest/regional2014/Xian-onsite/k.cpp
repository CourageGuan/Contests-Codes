#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a,b;

LL cal(LL a,LL b)
{
	LL res = 0;
	if(a < b) swap(a,b);
	if(!b) return 1;
	res += cal(a%b,b) + a/b;
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%lld %lld",&a,&b);
		if(a == 0 || b == 0)
		{
			printf("Case #%d: %lld\n",z,1+(a!=0 || b !=0));
			continue;
		}
		LL res = cal(a,b);
		printf("Case #%d: %lld\n",z,res);
	}
	return 0;
}
