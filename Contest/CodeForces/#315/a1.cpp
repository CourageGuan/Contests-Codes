#include<cstdio>

int main()
{
	int T,S,q;
	scanf("%d %d %d",&T,&S,&q);
	int cnt = 0;
	while(S<T)
	{
		S*=q;
		++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
