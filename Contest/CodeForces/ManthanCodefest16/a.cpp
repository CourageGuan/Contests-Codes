#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a,b,c;

bool yes()
{
	if(c%a == 0) return 1;
	for(int i=0;;++i)
	{
		c -= b;
		if(c < 0) break;
		if(c%a == 0) return 1;
	}
	return 0;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&a,&b,&c);
	puts(yes()?"Yes":"No");
	return 0;
}

