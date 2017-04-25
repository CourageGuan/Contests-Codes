#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof a)

const int maxn = 1e5 + 10;
int n,l;
int a[maxn],res[maxn];
LL sum = 0;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> l;
	F(i,1,n) scanf("%d",a+i);
	int j = 0;
	F(i,1,n-1) if(a[i]+a[i+1] >= l)
	{
		j = i;
		break;
	}
	if(!j)
		puts("Impossible");
	else
	{
		puts("Possible");
		for(int i=n-1;i>j;--i)
			printf("%d\n",i);
		F(i,1,j-1)
			printf("%d\n",i);
		printf("%d\n",j);
	}
	return 0;
}
