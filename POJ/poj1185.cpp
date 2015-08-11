//棋盘状态压缩dp
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn = 110;
int d[2][65][65];
int G[maxn];
int n,m;
vector<int> ST,C,sst[2];

void print(int x)
{
	for(int i=0;i<m;++i)
		putchar(x&(1<<i)?'1':'0');
	puts("");
}

int cal(int x)
{
	int cnt = 0;
	while(x)
	{
		if(x&1) ++cnt;
		x>>=1;
	}
	return cnt;
}

void dfs(int p,int cur,int last)
{
	if(cur>=m)
	{
		ST.push_back(p);
		C.push_back(cal(p));
		return;
	}
	if(cur-last>2) dfs(p<<1|1,cur+1,cur);
	dfs(p<<1,cur+1,last);
}

int main()
{
	//freopen("test.txt","r",stdin);

	while(scanf("%d %d",&n,&m) == 2)
	{
		if(!n)
		{
		   	puts("0");
			continue;
		}

		ST.clear();
		C.clear();
		for(int i=0;i<2;++i) sst[i].clear();

		dfs(0,0,-3);

		for(int i=1;i<=n;++i)
		{
			char s[20];
			scanf("%s",s);
			int t=0;
			for(int j=0;j<m;++j)
			{
				if(s[j] == 'P') t|=1;
				t <<= 1;
			}
			t>>=1;
			G[i] = t;
	//		print(t);
		}

		memset(d,0,sizeof d);

		for(int i=0;i<ST.size();++i)
		{
			if( (ST[i]|G[1]) != G[1] ) continue;
			//print(ST[i]);
			d[0][i][0] = C[i];
		}

		if(n<=1)
		{
			int ans = 0;
			for(int i=0;i<ST.size();++i) ans = max(ans,d[0][i][0]);
			printf("%d\n",ans);
			continue;
		}


		for(int i=0;i<ST.size();++i)
		{
			for(int j=0;j<ST.size();++j)
			{
				if(ST[i]&ST[j]) continue;
				sst[0].push_back(j);
				sst[1].push_back(i);
			}
		}

		for(int j=0;j<sst[0].size();++j)
		{
			int t1=sst[0][j],t2=sst[1][j];
			if((ST[t1]|G[2])!=G[2] || (ST[t2]|G[1])!=G[1]) continue;
			d[1][t1][t2] = max(d[1][t1][t2],d[0][t2][0] + C[t1]);
		}

		if(n<=2)
		{
			int ans = 0;
			for(int j=0;j<sst[0].size();++j)
			{
				int t1=sst[0][j],t2=sst[1][j];
				ans = max(ans,d[1][t1][t2]);
			}
			printf("%d\n",ans);
			continue;
		}
		
		for(int i=3;i<=n;++i)
		{
			int t=(i-1)&1;
			for(int j=0;j<sst[0].size();++j)
			{
				int t1=sst[0][j] , t2 = sst[1][j];
				if((ST[t1]|G[i])!=G[i] || (ST[t2]|G[i-1])!=G[i-1]) continue;
				for(int k=0;k<ST.size();++k)
				{
					if((ST[k]|G[i-2])!=G[i-2] || (ST[k]&ST[t1]) || (ST[k]&ST[t2])) continue;
					if(d[t][t1][t2] < d[t^1][t2][k] + C[t1])
					{
						d[t][t1][t2] = max(d[t][t1][t2],d[t^1][t2][k]+C[t1]);
						/*printf("%d %d\n",i,d[t][t1][t2]);
						print(ST[k]);
						print(ST[t2]);
						print(ST[t1]);
						puts("");
						*/
					}
				}
			}
		}

		int ans = 0;
		for(int j=0;j<sst[0].size();++j)
		{
			int t1=sst[0][j],t2=sst[1][j];
			ans = max(ans,d[(n-1)&1][t1][t2]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

