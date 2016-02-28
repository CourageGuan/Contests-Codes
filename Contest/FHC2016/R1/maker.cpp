#include<bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(0));
	puts("1");
	int n = rand()%10 + 1;
	printf("%d\n",n);
	for(int i=0;i<n;++i) printf("%d ",rand()%100+1);
	return 0;
}
