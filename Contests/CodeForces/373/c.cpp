#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
int n,t,tot;
char s[maxn];
int d[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&t);
	scanf("%s",s);
	int tot = -1,p,j;
	F(i,0,n-1)
	{
	   	if(s[i] != '.')
		{
			d[++tot] = s[i] - '0';
		}
		else p = tot;
	}
	j = p + 1;
	while(j <= tot && d[j] < 5) ++j;
	if(j <= tot)
	{
		tot = j;
		while(j)
		{
			if(d[j] >= 10) d[j] = 0,d[j-1]++;
			else if(j > p)
			{
				if(d[j] >= 5)
				{
				   	if(t)
					{
					   	d[j] = 0,d[j-1]++;
						--t;
					}
				}
			}
			--j;
		}
	}
	while(d[tot] == 0 && tot > p) --tot;
	F(i,0,tot)
	{
	   	printf("%d",d[i]);
		if(i == p && i != tot) putchar('.');
	}
	puts("");
	return 0;
}
