#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const double pi = acos(-1.0);

int main()
{
	//freopen("test.txt","r",stdin);
	int d,h,v,e;
	scanf("%d %d %d %d",&d,&h,&v,&e);
	double res = v/((1.0*d/2)*(1.0*d/2)*pi) - e;
	if(res > 0)
	{
		puts("YES");
		printf("%.6f",h/res);
	}
	else puts("NO");
}
