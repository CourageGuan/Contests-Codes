#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof a)

const int maxn = 1e5 + 10;
int ball[maxn],yes[maxn],x[maxn],y[maxn];
int n,m;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m;
	R(i,m) scanf("%d%d",x+i,y+i);
	F(i,1,n) ball[i] = 1;
	yes[1] = 1;
	R(i,m)
	{
		if(yes[x[i]]) yes[y[i]] = 1;
		ball[x[i]]--;
		ball[y[i]]++;
		if(ball[x[i]] == 0) yes[x[i]] = 0;
	}
	int cnt = 0;
	F(i,1,n) if(yes[i] && ball[i]) ++cnt;
	printf("%d\n",cnt);
	return 0;
}
