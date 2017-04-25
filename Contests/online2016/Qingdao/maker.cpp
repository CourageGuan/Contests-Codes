#include<bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(0));
	int T = 2;
	printf("%d\n",T);
	while(T--)
	{
		int n = 5,a,t;
		printf("%d\n",n);
		for(int i=0;i<n;++i) 
		{
			int len = 1 + rand()%3;
			for(int j=0;j<len;++j)
			{
				a = rand()%2,t = rand()%26;
				putchar('a'+t);
			}
			puts("");
		}
		int len = 22 + rand()%222;
		for(int i=0;i<len;++i)
		{
			a = rand()%2,t = rand()%26;
			if(a) putchar('a'+t);
			else putchar('A'+t);
		}
		puts("");
	}
	return 0;
}
