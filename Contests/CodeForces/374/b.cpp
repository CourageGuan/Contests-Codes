#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 110;
int n,k;
char s[maxn][maxn];

int cal(int t)
{
	if(t <= k) return t;
	return (t-1)/k * (k+5) + (t-1)%k + 1;
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);
	F(i,1,n) scanf("%s",s[i]);
	scanf("%s",s[0]);
	int cnt1 = 0,cnt2 = 0,len = strlen(s[0]);
	F(i,1,n) if(strlen(s[i]) < len) ++cnt1;
	else if(strlen(s[i]) == len) ++cnt2;
	printf("%d %d\n",cal(cnt1+1),cal(cnt1+cnt2));
	return 0;
}
