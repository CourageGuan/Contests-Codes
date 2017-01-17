#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int n = 20;
int d[n+10][n+10];

LL solve()
{
	LL res = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",&d[i][j]);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			LL cur;
			if(j+3<n)
			{
				cur = 1;
				for(int k=0;k<4;++k)
					cur *= d[i][j+k];
				res = max(res,cur);
			}

			if(i+3<n)
			{
				cur = 1;
				for(int k=0;k<4;++k)
					cur *= d[i+k][j];
				res = max(res,cur);
			}

			if(i+3 < n && j+3 < n)
			{
				cur = 1;
				for(int k=0;k<4;++k)
					cur *= d[i+k][j+k];
				res = max(res,cur);
			}

			if(i+3<n && j-3>=0)
			{
				cur = 1;
				for(int k=0;k<4;++k)
					cur *= d[i+k][j-k];
				res = max(res,cur);
			}
		}
	}
	return res;
}

int main()
{
	freopen("11.txt","r",stdin);
	printf("%lld\n",solve());
	return 0;
}
