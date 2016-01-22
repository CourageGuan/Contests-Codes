#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	if(n&1) puts("0");
	else printf("%d\n",n/4 - (n%4 == 0));
	return 0;
}
