#include<cstdio>
#include<cstring>
using namespace std;

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int cnt = 0;
		for(int i=1;i<=n;++i) if(gcd(i,n+1)==1) ++cnt;
		printf("%d\n",cnt);
	}
	return 0;
}
