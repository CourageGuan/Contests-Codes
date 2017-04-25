#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=(n+1)/2;++i)
		printf("%d ",2*i-1);
	for(int i=n/2;i>=1;--i)
		printf("%d ",2*i-1);
	for(int i=1;i<=n/2;++i)
		printf("%d ",2*i);
	for(int i=(n-1)/2;i>=1;--i)
		printf("%d ",2*i);
	printf("%d ",n);
	return 0;
}
