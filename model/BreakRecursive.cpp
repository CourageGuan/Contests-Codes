#include<cstdio>


void dfs(int n)
{
	printf("before *** %d\n",n);
	if(n == 5)
	{
		puts("OK");
		throw 1;
	}
	dfs(n-1);
	printf("after *** %d\n",n);
}

int main()
{
	try
	{
		dfs(10);
	}
	catch(int)
	{
		puts("Over");
	}
	return 0;
}
