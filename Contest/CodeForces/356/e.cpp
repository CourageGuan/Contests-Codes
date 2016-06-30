#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 510;

char g[maxn][maxn];
int col[maxn][maxn],v[maxn*maxn],b[maxn*maxn],cnt,n,k,sum;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x,int y,int c)
{
	col[x][y] = c;
	++cnt;
	for(int i=0;i<4;++i)
	{
		int tx = x+dx[i],ty = y+dy[i]; 
		if(tx < 0 || ty < 0 || tx >= n || ty >= n || g[tx][ty] == 'X' || col[tx][ty]) continue;
		dfs(tx,ty,c);
	}
}

void add(int x,int y)
{
	if(col[x][y] && ++v[col[x][y]] == 1) sum += b[col[x][y]];
}

void dec(int x,int y)
{
	if(col[x][y] && --v[col[x][y]] == 0) sum -= b[col[x][y]];
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i) scanf("%s",g[i]);
	int c = 1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		if(g[i][j]=='.' && !col[i][j])
		{
			cnt = 0;
			dfs(i,j,c);
			b[c++] = cnt;
		}
	}
	//for(int i=0;i<n;++i)
	//{
	//	for(int j=0;j<n;++j)
	//		printf("%2d ",b[col[i][j]]);
	//	puts("");
	//}
	int ans = 0;

	for(int i=0;i+k<=n;++i)
	{
		memset(v,0,sizeof v);
		sum = 0;
		for(int x=0;x<k;++x)
		{
			for(int y=0;y<k;++y)
			{
				add(x+i,y);
				if(!col[x+i][y]) ++sum;
			}
			if(i+k < n) add(i+k,x);
			if(k < n) add(x+i,k);
			if(i) add(i-1,x);
		}
//		printf("%d\n",sum);
		ans = max(ans,sum);
		for(int j=1;j+k<=n;++j)
		{
			if(i)
			{
				if(j-1>=0) dec(i-1,j-1);
				add(i-1,j+k-1);
			}
			if(i+k < n)
			{
				if(j-1>=0) dec(i+k,j-1);
				add(i+k,j+k-1);
			}

			if(j-1>=0)
				for(int t=0;t<k;++t)
					if(!col[i+t][j-1])
						--sum;


			if(j-2>=0)
				for(int t=0;t<k;++t)
					dec(i+t,j-2);

			if(j+k-1 < n)
				for(int t=0;t<k;++t)
					if(!col[i+t][j+k-1]) ++sum;


			if(j+k <= n)
				for(int t=0;t<k;++t)
					add(i+t,j+k);

//			printf("..%d\n",sum);
			ans = max(ans,sum);
		}
	}
	printf("%d\n",ans);
	return 0;
}

