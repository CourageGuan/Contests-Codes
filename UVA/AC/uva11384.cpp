//每次减去中间的数，直至为1
#include<cstdio>
#include<iostream>
using namespace std;

int cal(int n)
{
	return n==1?1:cal(n/2)+1;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1) printf("%d\n",cal(n));
	return 0;
}
