#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const LL t[3] = {1234567,123456,1234};
int n;

int main()
{
	//freopen("test","r",stdin);
	int flag = 0;
	cin >> n;
	for(int i=0;;++i)
	{
		if(i*t[0] > n) break;
		for(int j=0;;++j)
		{
			if(i*t[0] + j*t[1] > n) break;
			if((n - (i*t[0] + j*t[1]))%t[2] == 0) flag = 1;
			if(flag) break;
		}
		if(flag) break;
	}
	puts(flag?"YES":"NO");
	return 0;
}
