#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int val[] = {6,2,5,5,4,5,6,3,7,6};

int main()
{
	//freopen("test.txt","r",stdin);
	int a,b;
	scanf("%d %d",&a,&b);
	LL ans = 0;
	for(int i=a;i<=b;++i)
	{
		int t = i;
		do
		{
			ans += val[t%10];
			t/=10;
		}while(t);
	}
	printf("%lld\n",ans);
	return 0;
}
