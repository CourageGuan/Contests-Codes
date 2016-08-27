#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int main()
{
	//freopen("test.txt","r",stdin);
	int n,b,d,a;
	LL sum = 0,res = 0;
	cin >> n >> b >> d;
	R(i,n)
	{
		scanf("%d",&a);
		if(a > b) continue;
		sum += a;
		if(sum > d)
		{
			sum = 0;
			++res;
		}
	}
	printf("%d\n",res);
	return 0; 
}
