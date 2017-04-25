#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
char s[maxn],ss[maxn];
int cnt[10],n,m;

void dec(int t)
{
	do
	{
		--cnt[t%10];
		t /= 10;
	}while(t);
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s %s",s,ss);
	n = strlen(s);
	for(int i=0;i<n;++i) ++cnt[s[i]-'0'];
	if(n == 1)
	{
		puts("0");
		return 0;
	}
	int cur = 1;
	for(int i=1;i<9;++i)
	{
		if(cur <= n-i && n-i < cur*10)
		{
			n -= i;
			dec(n);
			break;
		}
		cur *= 10;
	}
	m = strlen(ss);
	for(int i=0;i<m;++i) --cnt[ss[i]-'0'];
	int p = 0;
	while(p < m && ss[p] == ss[0]) ++p;
	if(p < m && ss[p]>ss[0]) p = 1;
	else p = 0;
	for(int i=1;i<10;++i)
	{
		if(ss[0]-'0' == i)
		{
			if(!cnt[ss[0]-'0'])
			{
				printf("%s",ss);
				p = -1;
				break;
			}
			else
			{
				int t = 1;
				int flag = -1;
				while(1)
				{
					for(int j=0;j<=i;++j)
					{
						if(t >= m)
						{
							flag = 1;
							break;
						}
						if(!cnt[j]) continue;
						for(int k=0;k<cnt[j];++k)
						{

							if(t >= m)
							{
								flag = 1;
								break;
							}
							if(ss[t]-'0' > j)
							{
								flag = 0;
								break;
							}
							else if(ss[t]-'0' < j)
							{
								flag = 1;
								break;
							}
							++t;
						}
						if(flag != -1) break;
					}
					if(flag != -1) break;
				}
				if(flag == 1)
				{
					printf("%s",ss);
					p = -1;
					break;
				}
			}
		}
		if(cnt[i])
		{
			putchar('0'+i);
			--cnt[i];
			break;
		}
	}
	for(int i=0;i<10;++i)
	{
		if(ss[0]-'0' == i && p==0)
		{
			printf("%s",ss);
			p = -1;
		}
		if(cnt[i])
		{
			for(int j=0;j<cnt[i];++j) putchar('0'+i);
		}
		if(ss[0]-'0' == i && p>0)
		{
			printf("%s",ss);
			p = -1;
		}
	}
	puts("");
	return 0;
}
