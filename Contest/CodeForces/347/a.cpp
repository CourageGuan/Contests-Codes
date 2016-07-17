#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

char s[2];
int mark[110],cnt,res[110];
int inc,de,n;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%s",s);
	mark[cnt++] = 1; ++inc;
	while(scanf("%s",s) == 1 && s[0] != '=')
	{
		if(s[0] == '-')
		{
			mark[cnt++] = -1;
			++de;
		}
		else
		{
			mark[cnt++] = 1;
			++inc;
		}
		scanf("%s",s);
	}
	scanf("%d",&n);
	int t = n;
	bool flag = true;
	for(int i=0;i<cnt;++i)
		if(mark[i] == -1)
		{
			--de;
			res[i] = min(n,n*inc-de-t);
			t += res[i];
			if(res[i] < 1)
			{
				flag = false;
				break;
			}
		}
	if(t > n*inc) flag = false;
	for(int i=0;i<cnt;++i)
		if(mark[i] == 1)
		{
			--inc;
			res[i] = min(n,t-inc);
			t -= res[i];
			if(res[i] < 1)
			{
				flag = false;
				break;
			}
		}
	if(t != 0) flag = false;
	if(!flag) puts("Impossible");
	else
	{
		puts("Possible");
		for(int i=0;i<cnt;++i)
		{
			if(i == 0)
				printf("%d ",res[i]);
			else
				printf("%c %d ",mark[i]==1?'+':'-',res[i]);
		}
		printf("= %d\n",n);
	}
	return 0;
}

