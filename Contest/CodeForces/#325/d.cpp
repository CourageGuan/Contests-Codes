#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 110;
int n,m;
int p[maxn],line[maxn],len[maxn];
bool vis[3][maxn];

struct P
{
	int t,r;
	P() {}
	P(int t,int r):t(t),r(r) {}
};

bool bfs(int po)
{
	queue<P> Q;

	Q.push(P(0,po));
	memset(vis,0,sizeof vis);
	vis[po][0] = 1;

	while(!Q.empty())
	{
		P u = Q.front(); Q.pop();

		int t = u.t,r = u.r;

	//	printf("%d %d\n",t,r);

		if(t == n-1) return true;

		int flag = 1;

		for(int i=0;i<m;++i)	
		{
			if(line[i] != r) continue;

			if(t+1 == p[i] - t*2)
			{
				flag = -1;
				break;
			}

				if((t+1 >= p[i]-t*2 && t+1 <= p[i]-t*2+len[i]-1) || (t+1 >= p[i]-(t+1)*2 && t+1 <= p[i]-(t+1)*2+len[i]-1))
			{ 
				flag = 0;
				break;
			}
		}

		if(flag == -1) continue;

		if(flag && !vis[r][t+1])
		{ 
			vis[r][t+1] = 1;
			Q.push(P(t+1,r));
		}

		if(r >= 1)
		{
			flag = 1;
			for(int i=0;i<m;++i)	
			{
				if(line[i] != r-1) continue;

				if((t+1 >= p[i]-t*2 && t+1 <= p[i]-t*2+len[i]-1) || (t+1 >= p[i]-(t+1)*2 && t+1 <= p[i]-(t+1)*2+len[i]-1))
				{ 
					flag = 0;
					break;
				}
			}
			if(flag && !vis[r-1][t+1])
			{
				vis[r-1][t+1] = 1;
				Q.push(P(t+1,r-1));
			}
		}

		if(r <= 1)
		{
			flag = 1;
			for(int i=0;i<m;++i)	
			{
				if(line[i] != r+1) continue;

				if((t+1 >= p[i]-t*2 && t+1 <= p[i]-t*2+len[i]-1) || (t+1 >= p[i]-(t+1)*2 && t+1 <= p[i]-(t+1)*2+len[i]-1))
				{ 
					flag =  0;
					break;
				}
			}

			if(flag && !vis[r+1][t+1])
			{
				vis[r+1][t+1] = 1;
				Q.push(P(t+1,r+1));
			}
		}
	}
	return false;
}


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		int cnt = 0,po = 0;
		memset(len,0,sizeof len);
		for(int i=0;i<3;++i)
		{
			char s[maxn];
			scanf("%s",s);
			if(s[0] == 's') po = i;
			int j = 1;
			while(j<n)
			{
				if(s[j] != '.')
				{
					line[cnt] = i;
					p[cnt] = j;
					char ch = s[j];
					while(j<n && ch == s[j]) ++len[cnt],++j;
					++cnt;
				}
				else ++j;
			}
		}
		m = cnt;
		//for(int i=0;i<m;++i) printf("%d %d %d\n",line[i],p[i],len[i]);
		puts(bfs(po)?"YES":"NO");
	}
	return 0;
}

