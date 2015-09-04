#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 101;
const double eps = 1e-5;
double b[maxn];
char s[maxn][20],ss[maxn][20],sss[maxn][20];

int trans(char *s)
{
	int len = strlen(s);
	int res = 0;
	for(int i=0;i<len;++i)
	{
		res = res*10 + s[i] -'0';
	}
	return res;
}

bool yes(double a,double b,char *s)
{
	int len = strlen(s);
	if(s[0]=='=') return a == b;
	if(len==1)
	{
		if(s[0]=='<') return a < b;
		if(s[0]=='>') return a > b;
	}
	else
	{
		if(s[0]=='<') return a <= b;
		if(s[0]=='>') return a >= b;
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1)	
	{
		for(int i=0;i<n;++i)
		{
			scanf("%s %s %lf",ss[i],s[i],b+i);
		}
		int ans = 0;
		for(int j=0;j<n;++j)
		{
			double t;
			if(s[j][0]=='<') t= b[j] - eps;
			else if(s[j][0]=='>') t=b[j] + eps;
			else t = b[j];
			int cnt = 0;
			for(int i=0;i<n;++i)
			{
				if(yes(t,b[i],s[i])) ++cnt;
			}
			ans = max(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}

