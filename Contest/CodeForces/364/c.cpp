#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof (a))

const int maxn = 1e5 + 10 ;
int vis[255];
int cnt,n,tot;
char s[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	cin >> s;
	R(i,n) if(!vis[s[i]]) ++cnt,vis[s[i]] = 1;
	int res = n,j = 0;
	tot = cnt;
	cnt = 0;
	fill(vis,0);
	R(i,n)
	{
		while(j < n && cnt < tot)
		{
			if(!vis[s[j]]) ++cnt;
			vis[s[j]]++;
			++j;
		}
		if(j >= n && cnt < tot) break;
		res = min(res,j-i);
		vis[s[i]]--;
		if(!vis[s[i]]) --cnt;
	}
	printf("%d\n",res);
	return 0;
}
