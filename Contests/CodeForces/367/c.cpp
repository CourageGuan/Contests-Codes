#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define endl '\n'

const int maxn = 1e5 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n;
LL d[maxn][2];
int c[maxn];
string s[maxn],rs[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	std::ios::sync_with_stdio(false);	
	cin.tie(0);
	cin >> n;
	F(i,1,n) cin >> c[i];
	F(i,1,n)
	{
		cin >> s[i];
		rs[i] = s[i];
		reverse(rs[i].begin(),rs[i].end());
	}
	fill(d,INF);
	d[1][0] = 0;
	d[1][1] = c[1];
	F(i,2,n)
	{
		if(s[i] >= s[i-1]) d[i][0] = min(d[i][0],d[i-1][0]);
		if(s[i] >= rs[i-1]) d[i][0] = min(d[i][0],d[i-1][1]);

		if(rs[i] >= s[i-1]) d[i][1] = min(d[i][1],d[i-1][0] + c[i]);
		if(rs[i] >= rs[i-1]) d[i][1] = min(d[i][1],d[i-1][1] + c[i]);
	}
	LL ans = min(d[n][0],d[n][1]);
	if(ans >= INF) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}
