#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<=(n);++i)
#define fill(a,b) memset(a,b,sizeof a)


int main()
{
//	freopen("test.txt","r",stdin);
	int a,b;
	cin >> a >> b;
	if(a <= 0 && b >= 0)
		puts("Zero");
	else if((a > 0 && b > 0) || (b - a)&1)
		puts("Positive");
	else
		puts("Negative");

	return 0;
}
