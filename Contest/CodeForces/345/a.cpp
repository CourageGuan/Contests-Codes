#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a,b;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&a,&b);
	int cnt = 0;
	while(a > 0 && b > 0 && a + b > 2)
	{
		if(a < b) swap(a,b);
		a -= 2;
		++b;
		++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
