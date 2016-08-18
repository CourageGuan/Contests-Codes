#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int main()
{
	//freopen("test","r",stdin);
	string name;
	int n,flag = 0;
	cin >> n;
	while(n --)
	{
		int a,b;
		cin >> name >> a >> b;
		if(a >= 2400 && b > a) flag = 1;
	}
	puts(flag?"YES":"NO");
	return 0;
}
