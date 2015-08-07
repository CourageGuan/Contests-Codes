#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;

const int maxn  = 1000010;
int vis[maxn] ;
char s[102][2];
int id[102];
int n;

int solve()
{
	for(int i=0;i<=2*n;++i)
	{
		memset(vis,0,sizeof vis);
		bool flag = true;
		int sz = i,now = 0;
		int mx = i;
		for(int j=1;j<=n;++j)
		{
			if(s[j][0]=='+')
			{
				vis[id[j]] = 1;
				now++;
			}
			else
			{
				if(vis[id[j]]) now--;
				else --sz;
				vis[id[j]] = 0;
			}
			if(sz<0) { flag = false;break; }
			mx = max(mx,now+sz);
		}
		if(flag) return mx;
	}
	return n;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int pos;
		scanf("%s %d",s[i],id+i);
	}
	printf("%d\n",solve());
	return 0;
}



