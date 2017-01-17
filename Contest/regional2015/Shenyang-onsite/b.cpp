#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 510;
int n;
char s[maxn][2010];
bool vis[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d",&n);
		F(i,1,n) scanf("%s",s[i]);
		memset(vis,0,sizeof vis);
		int ans = -1;
		F(i,2,n)
		{
			bool flag = 0;
			F(j,1,i-1)
			{
				if(vis[j]) continue;
				if(!strstr(s[i],s[j])) flag = 1;
				else vis[j] = 1;
			}
			if(flag) ans = i;
		}
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}
