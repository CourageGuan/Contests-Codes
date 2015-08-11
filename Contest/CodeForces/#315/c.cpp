#include<bits/stdc++.h>
using namespace std;

const int maxn = 1300000;
int pi[maxn],n,p,q;
int rub[maxn];
double res[maxn];

inline bool yes(int n)
{
	int m=n,t=0;
	while(m)
	{
		t=t*10+m%10;
		m/=10;
	}
	return t==n;
}

void init()
{
	memset(pi,0,sizeof pi);
	for(int i=2;i<maxn;++i)
	{
		if(pi[i]==-1)
		{
			pi[i]=pi[i-1];
			continue;
		}
		for(int j=i+i;j<maxn;j+=i) pi[j] = -1;
		pi[i]=pi[i-1]+1;
	}
	rub[0] = 0;
	int i;
	for(i=1;i<maxn;++i)	
	{
		rub[i]=rub[i-1];
		if(yes(i)) ++rub[i];
		res[i] = (double)pi[i]/rub[i];
		if(res[i]>=43) break;
	}
	n = i;
}

int main()
{
	int p,q;
	init();
	while(scanf("%d %d",&p,&q)==2)
	{
		double A = (double)p/q;
		bool flag = false;
		for(int i=n-1;i>0;--i)
		{
			if(A>=res[i])
			{
				printf("%d\n",i);
				flag = true;
				break;
			}
		}
		if(flag) continue;
		puts("Palindromic tree is better than splay tree");
	}
	return 0;
}


