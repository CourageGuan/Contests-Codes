#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

LL d[25][25][2][2][2][2];
bool vis[25][25][2][2][2][2];
int n1,n2;
char a[25],b[25],ta[25];

LL dfs(int len1,int len2,int d1,int u1,int d2,int u2)
{
	if(len1 == n2) return (len2 < len1 || u2) && d2;
	LL& res=d[len1][len2][d1][u1][d2][u2];
	if(vis[len1][len2][d1][u1][d2][u2]) return res;
	vis[len1][len2][d1][u1][d2][u2] = 1;
	res = 0;
	int l = d1?0:a[len1]-'0';
	int r = u1?9:b[len1]-'0';
	for(int i=l;i<=r;++i)
	{
		int dd2 = i>a[n2-1-len2]-'0' || (d2 && i == a[n2-1-len2]-'0');
		int du2 = i<b[n2-1-len2]-'0' || (u2 && i == b[n2-1-len2]-'0');
		res += dfs(len1+1,len2+(len2 || i),d1 || i>l,u1 || i < r,!(len2 || i) || dd2,!(len2 || i) || du2);
	}
	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%s%s",ta,b);
		n1 = strlen(ta);
		n2 = strlen(b);
		memset(a,'0',sizeof a);
		sscanf(ta,"%s",a+n2-n1);
		memset(vis,0,sizeof vis);
		LL ans = dfs(0,0,0,0,1,1);
		printf("Case %d: %llu\n",z,ans);
	}
	return 0;
}
