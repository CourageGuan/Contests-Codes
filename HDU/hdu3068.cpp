//manacher 求最长回文子串
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 111111;

char s[maxn*2];
char ss[maxn];
int p[maxn*2],n;

void gao()
{
	memset(p,0,sizeof p);
	int mx = 0,id,ans = 0;
	for(int i=1;i<n;++i)
	{
		if(mx>i)
			p[i] = min(p[2*id - i],mx - i);
		else
			p[i] = 1;
		while(s[i+p[i]] == s[i-p[i]]) ++p[i];
		if(mx < i+p[i])
		{
			mx = i+p[i];
			id = i;
		}
		ans = max(ans,p[i]-1);
	}
	//printf("%s\n",s);
	printf("%d\n",ans);
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%s",ss)==1)
	{
		s[0] = '$';
		s[1] = '#';
		n = 2*strlen(ss) + 2;
		for(int i=2;i<n;++i)
		{
			if(i&1) s[i] = '#';
			else s[i] = ss[i/2-1];
		}
		gao();
	}
	return 0;
}


