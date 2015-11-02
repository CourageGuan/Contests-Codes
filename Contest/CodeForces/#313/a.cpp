#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int a[6];
inline int P(int a)
{
	return a*a;
}

int main()
{
	//freopen("test.txt","r",stdin);
	for(int i=0;i<6;++i) scanf("%d",a+i);	
	printf("%d\n",P(a[0]+a[1]+a[2])-P(a[0])-P(a[2])-P(a[4]));
	return 0;
}
