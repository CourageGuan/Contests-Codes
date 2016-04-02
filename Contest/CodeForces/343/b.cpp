#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 400;
int vis[2][maxn],n;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;++i)
	{
		char s[2];
		int a,b;
		scanf("%s",s);
		scanf("%d %d",&a,&b);
		if(s[0] == 'F')
			for(int t=a;t<=b;++t) ++vis[0][t];
		else
			for(int t=a;t<=b;++t) ++vis[1][t];
	}
	int ans = 0;
	for(int i=1;i<=366;++i) ans = max(ans,min(vis[0][i],vis[1][i]));
	printf("%d\n",ans*2);
	return 0;
}
