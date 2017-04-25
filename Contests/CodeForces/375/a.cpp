#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

int x[3];

int main()
{
//	freopen("test.txt","r",stdin);
	cin >> x[0] >> x[1] >> x[2];
	sort(x,x+3);
	printf("%d\n",x[2] - x[0]);
	return 0;
}
