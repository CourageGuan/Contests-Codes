#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d %d\n",2*(n/7)+(n%7==6),2*(n/7)+(n%7?(n%7>=2?2:1):0));
	return 0;
}
