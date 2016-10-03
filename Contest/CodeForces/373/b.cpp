#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e5 + 10;
int n;
char s[maxn];

int id(char c)
{
	return c == 'r'?0:1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",s);
	int cnt[2],res;
	cnt[0] = cnt[1] = 0;
	F(i,0,n-1)
		if(id(s[i]) != (i&1)) ++cnt[id(s[i])];
	res = max(cnt[id('r')],cnt[id('b')]);
	cnt[0] = cnt[1] = 0;
	F(i,0,n-1)
		if(id(s[i]) != (!(i&1))) ++cnt[id(s[i])];
	res = min(res,max(cnt[id('r')],cnt[id('b')]));
	printf("%d\n",res);
	return 0;
}
