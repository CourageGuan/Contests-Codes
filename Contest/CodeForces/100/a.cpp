#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)

const double pi = acos(-1.0);
const double eps = 1e-6;
int n,R,r;

int main()
{
//	freopen("test.txt","r",stdin);
	cin >> n >> R >> r;
//	printf("%lf\n",asin(1.0*r/(R-r)));
	if(R < r)
		puts("NO");
	else if(R < 2*r)
		puts(n <= 1?"YES":"NO");
	else
		puts(n<=(int)(pi/asin(1.0*r/(R-r))+eps)?"YES":"NO");
	return 0;
}
