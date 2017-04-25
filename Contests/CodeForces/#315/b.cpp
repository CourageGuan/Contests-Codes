#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn =100010;
int a[maxn];
int vis[maxn];
vector<int> un;

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1)
	{
		un.clear();
		for(int i=1;i<=n;++i) scanf("%d",a+i),++vis[a[i]];
		for(int i=1;i<=n;++i) if(!vis[i]) un.push_back(i);
		vector<int>::iterator it = un.begin();
		for(int i=1;i<=n;++i)
		{
			if((a[i]<=n && vis[a[i]]>1) || a[i]>n)
			{
				--vis[a[i]];
				printf("%d%c",*it,i==n?'\n':' ');
				it++;
				continue;
			}
			printf("%d%c",a[i],i==n?'\n':' ');
		}
	}
	return 0;
}
