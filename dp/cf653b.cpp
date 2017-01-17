#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

int g[100][100];
LL d[100][10];
int n,q;

int cal(char* s)
{
	int len = strlen(s);
	if(len == 1) return s[0] - 'a' + 1;
	else return 10*(s[0] - 'a' + 1) + (s[1] - 'a' + 1);
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&q);	
	F(i,1,q)
	{
		char s[2],ss[2];
		scanf("%s %s",s,ss);
		g[cal(ss)][cal(s)] = 1;
	}
	d[1][1] = 1;
	F(i,2,n)
	{
		F(j,1,6)
			F(k,1,66)
			{
				if(g[j][k])
					d[i][k/10] += d[i-1][j];
			}
	}
	LL ans = 0;
	F(i,1,6) ans += d[n][i];
	printf("%lld\n",ans);
	return 0;
}
