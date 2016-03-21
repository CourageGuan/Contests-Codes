#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
bool vis[maxn];

void init()
{
	freopen("test.txt","r",stdin);
	memset(vis,0,sizeof vis);
	int x;
	while(scanf("%d",&x)==1) vis[x] = 1;
}

int main()
{
	init();
	freopen("yes.lang","r",stdin);
	freopen("rem.txt","w",stdout);
	char s[maxn];
	for(int i=1;i<=100;++i)
	{
		gets(s);
		if(vis[i]) puts(s);
	}
	return 0;
}
