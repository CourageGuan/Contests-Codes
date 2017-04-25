#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 3010;
char s[maxn][maxn];
int L[maxn][maxn],R[maxn][maxn];
int n,m;
vector<int> over[maxn];
int bit[maxn];

int lowbit(int x)
{
	return x&-x;
}

int query(int p)
{
	++p;
	int res = 0;
	for(int i=p;i>0;i-=lowbit(i))
		res += bit[i];
	return res;
}

void add(int p,int val)
{
	++p;
	for(int i=p;i<maxn;i+=lowbit(i))
		bit[i] += val;
}

void init()
{
	for(int i=0;i<n;++i)
	{
		L[i][0] = s[i][0] == 'z';
		for(int j=1;j<m;++j)
		{
			if(s[i][j] == 'z') 
				L[i][j] = L[i][j-1] + 1;
			else
				L[i][j] = 0;
		}
		R[i][m-1] = s[i][m-1] == 'z';
		for(int j=m-2;j>=0;--j)
		{
			if(s[i][j] == 'z')
				R[i][j] = R[i][j+1] + 1;
			else
				R[i][j] = 0;
		}
	}
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i) scanf("%s",s[i]);
	init();
	LL ans = 0;
	for(int i=0;i<n;++i)
	{
		memset(bit,0,sizeof bit);
		for(int j=0;j<maxn;++j) over[j].clear();
		int x = i,y = 0,lst = -1;
		while(x >= 0 && y < m)
		{
			if(s[x][y] == '.')
				lst = y;
			else
			{
				add(y,1);
				over[y+R[x][y]-1].push_back(y);
				ans += query(y) - query(y - min(L[x][y],y - lst));
			}
			for(int j=0;j<over[y].size();++j) add(over[y][j],-1);
			--x;
			++y;
		}
	}
	for(int i=1;i<m;++i)
	{
		memset(bit,0,sizeof bit);
		for(int j=0;j<maxn;++j) over[j].clear();
		int x = n-1,y = i,lst = -1;
		while(y < m && x >= 0)
		{
			if(s[x][y] == '.')
				lst = y;
			else
			{
				add(y,1);
				over[y+R[x][y]-1].push_back(y);
				ans += query(y) - query(y - min(L[x][y],y - lst));
			}
			for(int j=0;j<over[y].size();++j) add(over[y][j],-1);
			--x;
			++y;
		}
	}
	printf("%lld\n",ans);
	return 0;
}


