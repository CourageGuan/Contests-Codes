#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	//freopen("test.txt","r",stdin);
	int a,b;		
	scanf("%d%d",&a,&b);
	if(a == 1 && b==10)
	{
	   	puts("-1");
		return 0;
	}
	if(b == 10)
	{
		printf("%d",1);
		for(int i=1;i<a;++i) printf("%d",0);
	}
	else
		for(int i=0;i<a;++i) printf("%d",b);
	puts("");
	return 0;
}
