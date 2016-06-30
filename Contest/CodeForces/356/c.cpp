#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,36,49};

int main()
{
	//freopen("test.txt","r",stdin);
	int cnt = 0;
	for(int i=0;i<20;++i)
	{
		printf("%d\n",primes[i]);
		fflush(stdout);

		char s[10];
		scanf("%s",s);
		if(s[0] == 'y')
		{
			++cnt;
			if(cnt > 1) break;
		}
	}
	puts(cnt>1?"composite":"prime");
	fflush(stdout);
	return 0;
}
