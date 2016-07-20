#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;

int a[18],b[18],la,lb;
bool vis[10];
int res = 0;

int ans = 0;

void dfs(int t,int li)
{
	if(t >= la+lb)
	{
		++ans;
		return;
	}
	if(t >= lb)
	{
		if(t == lb)
		{
			for(int i=0;i<=a[la-1];++i)
			{
				if(vis[i]) continue;
				vis[i] = 1;
				dfs(t+1,i == a[la-1]);
				vis[i] = 0;
			}
		}
		else
		{
			for(int i=0;i<=(li?a[la-1-(t-lb)]:6);++i)
			{
				if(vis[i]) continue;
				vis[i] = 1;
				dfs(t+1,li && i == a[la-1-(t-lb)]);
				vis[i] = 0;
			}
		}
	}
	else
	{
		for(int i=0;i<=(li?b[lb-1-t]:6);++i)
		{
			if(vis[i]) continue;
			vis[i] = 1;
			dfs(t+1,li && i == b[lb-1-t]);
			vis[i] = 0;
		}
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	cin >> n >> m;
	--m;--n;
	int t = n,i=0;
	do
	{
		a[i++] = t%7;
		t/=7;
	}while(t);
	la = i;
	t = m,i = 0;
	do
	{
		b[i++] = t%7;
		t/=7;
	}while(t);
	lb = i;
	if(la + lb > 7)
	{
		puts("0");
		return 0;
	}
//	printf("%d %d\n",la,lb);
	for(int i=0;i<=b[lb-1];++i)
	{
		memset(vis,0,sizeof vis);
		vis[i] = 1;
//		printf("%d\n",i);
		dfs(1,i == b[lb-1]);
	}
	printf("%d\n",ans);
	return 0;
}
