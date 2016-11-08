#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 +10 ;
int n;
char s[maxn];
int len[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",s);
	if(n == 1)
	{
		puts("1");
		return 0;
	}
	int cnt = 0,l = 1;
	for(int i=1;i<n;++i)
	{
		if(s[i] != s[i-1])
		{
			len[cnt++] = l;
			l = 0;
		}
		++l;
		if(i == n-1)
		{
			len[cnt++] = l;
		}
	}

	int ans = cnt;
	for(int i=0;i<cnt;++i)
	{
		if(len[i] >= 3)
		{
			ans = cnt+2;
			break;
		}
		else if(len[i] == 2)
		{
			++ans;
			if(ans == cnt+2) break;
		}
	}

	printf("%d\n",min(n,ans));
	return 0;
}


