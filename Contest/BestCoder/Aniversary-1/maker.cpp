#include<cstdio>


int main()
{
	freopen("queue.txt","w",stdout);
	int n = 100;
	for(int i=1;i<=n;++i)
		printf("%d %d\n",i,3*i*(i-1)+1);
	return 0;
}
