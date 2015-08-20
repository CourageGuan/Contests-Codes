//区间dp dp(i,j) 表示最小染色次数
// s[i] == s[j] min(dp(i+1,j),dp(i,j-1),dp(i+1,j-1)+1)
// s[i] != s[j] min(dp(i,k)+dp(k+1,j))
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 55;
const int INF = 0x3f3f3f3f;
int d[maxn][maxn],n;
char s[maxn];

int dp(int i,int j)
{
	if(i == j) return 1;
	int &ans = d[i][j];
	if(ans!=-1) return ans;
	ans = INF;
	if(s[i]==s[j])
	{
		ans = min(dp(i+1,j),dp(i,j-1));
		ans = min(ans,dp(i+1,j-1)+1);
	}
	else
	{
		for(int k=i;k<j;++k)
		{
			ans = min(ans,dp(i,k)+dp(k+1,j));
		}
	}
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	char ss[maxn];
	while(scanf("%s",ss)==1)
	{
		memset(d,-1,sizeof d);
		n = strlen(ss);
		int cnt=0;
		s[cnt++] = ss[0];
		for(int i=1;i<n;++i)
		{
			if(ss[i]!=ss[i-1]) s[cnt++] = ss[i];
		}
		//for(int i=0;i<cnt;++i) putchar(s[i]);
		printf("%d\n",dp(0,cnt-1));
	}
	return 0;
}
