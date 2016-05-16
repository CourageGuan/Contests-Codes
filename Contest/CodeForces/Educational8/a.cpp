#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	//freopen("test.txt","r",stdin);
	int P[10] = {0,2,4,8,16,32,64,128,256,512};
	int n,b,p,res = 0,ans ;
	scanf("%d %d %d",&n,&b,&p);
	ans = n*p;
	for(int j=9;j>=1;--j)
	{
		while(n >= P[j])
		{
			res += P[j]/2;
			n -= P[j]/2;
		}
	}
	printf("%d %d\n",res*(b*2+1),ans);
	return 0;
}
