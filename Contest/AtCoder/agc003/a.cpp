#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1010;
int cnt[4];
char s[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s",s);
	R(i,strlen(s))
	{
		if(s[i] == 'E') cnt[0]++;
		if(s[i] == 'S') cnt[1]++;
		if(s[i] == 'W') cnt[2]++;
		if(s[i] == 'N') cnt[3]++;
	}
	R(i,2)
	if((!cnt[i] && cnt[i+2]) || (cnt[i] && !cnt[i+2]))
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}
