#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

queue<LL> q;
const int maxn = 1e6 + 10;
int a[maxn];
int n,t;

bool yes(int k)
{
	while(q.size()) q.pop();
	int i = 0,rem = n;
	LL cost = 0;
	int fi = 0;
	while(1)
	{
		int s = k;
		if(!fi)
		{
			if(rem%(k-1) != 1)
			{
				s = rem%(k-1);
				if(s == 0) s = k-1;
			}
			fi = 1;
		}
		LL cur = 0;
		while(s--)
		{
			if(!q.size() && i >= n) break;
			LL u;
			if(q.size() && i >= n)  
			{
				u = q.front();
				q.pop();
			}
			else if(!q.size() && i < n)
			{
				u = a[i];
				++i;
			}
			else
			{
				if(q.front() <= a[i])
				{
					u = q.front();
					q.pop();
				}
				else
				{
					u = a[i];
					++i;
				}
			}
			cur += u;
		}
		cost += cur;
		if(cost > t) return 0;
		if(!q.size() && i >= n) break;
		q.push(cur);
	}
	return 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int	T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&t);
		int l = 2,r = n,res = n;
		F(i,0,n-1)
			scanf("%d",a+i);
		sort(a,a+n);
		while(l <= r)
		{
			int m = (l+r) >> 1;
			if(yes(m))
			{
				res = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		printf("%d\n",res);
	}
	return 0;
}
