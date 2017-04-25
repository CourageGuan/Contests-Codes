#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
const int INF = 0x3f3f3f3f;


int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	cin >> n;
	F(i,1,n-1)
	{
		if(i&1) printf("I hate that ");
		else printf("I love that ");
	}
	if(n&1) printf("I hate it");
	else printf("I love it");
	return 0;
}
