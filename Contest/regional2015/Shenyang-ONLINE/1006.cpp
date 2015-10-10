#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long LL;

const int maxn = 2000200;
char s[maxn];

int solve()
{
	int n = strlen(s);
	int ans = 0,i=0,len = n;
	while(i<n && s[i]=='f') s[i+n]='f',++i,++len;
//	printf("%d\n",len);
	for(;i<len;)
	{
		if(s[i] == 'c')
		{
			++i;
			int cnt = 0;
			while(i<len && s[i]=='f') ++cnt,++i;
			if(cnt<2) return -1;
			++ans;
		}
		else
		if(s[i] == 'f')
		{
			int cnt = 0;
			while(i<len && s[i]=='f' && cnt<2) ++cnt,++i;
			++ans;
		}
		else return -1;
	}
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%s",s);
		printf("Case #%d: %d\n",z,solve());
	}
	return 0;
}

