#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn];
int vis[2*maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	int i,j,cur = 0,ans = 0,end = 0;
	i = j = 0;
	memset(vis,0,sizeof vis);
	while(j<n)
	{
		if(!vis[a[j]]) ++cur;
		++vis[a[j]];
		//printf("%d\n",cur);
		while(cur>k)
		{
			--vis[a[i]];
			if(!vis[a[i]]) --cur;
			++i;
		}
		//printf("%d %d\n",i,j);
		if(j-i+1 > ans)
		{
			ans = j-i+1;
			end = j;
		}
		++j;
	}
	printf("%d %d\n",end-ans+2,end+1);
	return 0;
}
