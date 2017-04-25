#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
int n,s,tt;
int a[maxn];
int vis[maxn];

void solve()
{
	scanf("%d %d",&n,&s);
	F(i,0,n-1) scanf("%d",a+i),vis[a[i]]++;
	vis[a[s-1]]--;
	if(a[s-1] != 0) a[s-1] = 0,tt = 1;
	sort(a,a+n);
	int t = 0,res = 0,r = n - 1;
	a[n] = 1;
	F(i,1,n) if(a[i])
	{
	   	t = i-1;
		break;
	}
	F(i,1,n-1) 
	{
		if(!t) break;
		if(!vis[i])
		{
			vis[i] = 1;
			--t;
			++res;
		}
	}
	if(t) res = t;
	else
	{
		F(i,1,n-1)
		{
			if(i >= a[r]) break;
			if(!vis[i])
			{
				vis[i] = 1;
				--vis[a[r]];
				--r;
				++res;
			}
		}
	}
	printf("%d\n",res+tt);
}

int main()
{
//	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
