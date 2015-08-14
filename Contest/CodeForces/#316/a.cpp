#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 110;
int pic[maxn][maxn];
int st2[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	while(scanf("%d %d",&n,&m)==2)
	{
		memset(st2,0,sizeof st2);
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				scanf("%d",&pic[i][j]);
			}
		}

		for(int i=0;i<m;++i)
		{
			int mx = 0;
			for(int j=0;j<n;++j)
			{
				mx = max(mx,pic[i][j]);
			}
			for(int j=0;j<n;++j)
			{
				if(mx==pic[i][j]) 
				{
					st2[j]++;
					break;
				}
			}
		}
		int idx2 = 0, mx = 0;
		for(int i=0;i<n;++i)
		{
			if(st2[i]>mx)
			{
				mx = st2[i];
				idx2 = i;
			}
		}
		printf("%d\n",idx2+1);
	}
	return 0;
}
