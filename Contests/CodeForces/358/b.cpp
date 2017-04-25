#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int n;
int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	R(i,n) scanf("%d",a+i);
	sort(a,a+n);
	int res = 1;
	R(i,n) if(a[i] >= res) ++res;
	printf("%d\n",res);
	return 0;
}
