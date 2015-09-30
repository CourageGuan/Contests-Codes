#include<bits/stdc++.h>
using namespace std;

typedef long long LL;


int main()
{
	//freopen("test.txt","r",stdin);
	int a,b	;
	scanf("%d %d",&a,&b);
	printf("%d %d\n",min(a,b),(max(a,b) - min(a,b))/2);
	return 0;
}
