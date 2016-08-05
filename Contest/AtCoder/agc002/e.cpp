#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof a)

const int maxn = 1e5 + 10;
int n;
int a[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	R(i,n) scanf("%d",a+i);
	sort(a,a+n,greater<int>());
	int c = 0;
	while(c+1 < n && c+1 < a[c+1]) ++c;
	int t = a[c] - c,p = 1;
	F(i,c+1,n-1)
		if(a[i] == c+1) ++p;
		else break;
//	printf("%d %d\n",t,p);
	if((t&1) && (p&1))
		puts("Second");
	else
		puts("First");
	return 0;
}
