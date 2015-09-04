#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100010;
int pn ;
bool is[maxn];
int prm[30010];

void init()
{
	memset(is,0,sizeof is);
	pn = 0;
	for(int i=2;i<31623;++i)
	{
		if(!is[i])
		{
			prm[pn++] = i;
			for(int j=i+i;j<31623;j+=i) is[j] = 1;
		}
	}
}

void fac(int n,vector<int> &p,vector<int> &e)
{
	p.clear();
	e.clear();
	while(n%2==0) n/=2;
	while(n%3==0) n/=3;
	for(int i=2;i<pn;++i)
	{
		if(n%i == 0)
		{
			int cnt = 0;
			while(n%i==0)
			{
				n/=i;
				++cnt;
			}
			p.push_back(i);
			e.push_back(cnt);
		}
		if(n==1) break;
	}
	if(n>1)
	{
		p.push_back(n);
		e.push_back(1);
	}
}

int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	init();
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;++i)
		{
		   	scanf("%d",a+i);
		}
		vector<int> p,e;
		fac(a[0],p,e);
		bool flag = true;
		for(int i=1;i<n;++i)
		{
			vector<int> pp,ee;
			fac(a[i],pp,ee);
			if(p.size()!=pp.size())
			{
			  	flag = false;
				break;
			}
			for(int i=0;i<p.size();++i)
			{
				if(p[i]!=pp[i] || e[i]!=ee[i])
				{ 
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}

