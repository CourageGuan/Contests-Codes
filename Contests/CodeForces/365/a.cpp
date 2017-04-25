#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))


int main()
{
//	freopen("test.txt","r",stdin);
	int n,cnt = 0;
	cin >> n;
	R(i,n)
	{
		int a,b;
		cin >> a >> b;
		if(a > b) cnt++;
		if(a < b) cnt--;
	}
	if(!cnt) puts("Friendship is magic!^^");
	else puts(cnt>0?"Mishka":"Chris");
	return 0;
}
