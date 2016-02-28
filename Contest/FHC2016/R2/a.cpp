#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
char s[2][maxn];
int re[2][maxn];
const int INF = 0x3f3f3f3f;

int main()
{
	//freopen("test.txt","r",stdin);
    freopen("boomerang_decoration.txt","r",stdin);
	freopen("ans_a.txt","w",stdout);
	int n,T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		scanf("%s %s",s[0],s[1]);
		memset(re,0,sizeof re);
		for(int i=0;i<n;++i)
		{
			if(i)
			{
				if(s[1][i] == s[1][i-1])
				{
					re[0][i] = re[0][i-1];
				}
				else re[0][i] = re[0][i-1] + 1;
			}
			else re[0][i] = 1;
		}
		for(int i=n-1;i>=0;--i)
		{
			if(i!=n-1)
			{
				if(s[1][i] == s[1][i+1])
				{
					re[1][i] = re[1][i+1];
				}
				else re[1][i] = re[1][i+1] + 1;
			}
			else re[1][i] = 1;
		}
		int ans = INF;
		int i=0,j=0;
		do
		{
			while(i<n && s[0][i] == s[1][i]) ++i;
			j = i+1;
			while(j<n && s[0][j] == s[1][j]) ++j;
			ans = min(ans,max(re[0][i],re[1][j]));
			i = j;
		}while(i<n && j<n);
		if(ans == INF) ans = 0;
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}

