#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)

const int maxn = 310;
int choose[maxn],res[maxn],n;
int p[maxn][maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	F(i,1,n+1)
	{
		int t;
		F(j,1,n)
		{
			scanf("%d",&t);
			p[i][t] = j;
		}
		p[i][0] = n+1;
	}
	int t1 = 0,t2 = 0;
	F(i,1,n)
	{
		if(p[n+1][i] < p[n+1][t1])
		{
			t2 = t1;
			t1 = i;
		}
		else if(p[n+1][i] < p[n+1][t2])
		{
			t2 = i;
		}
//		printf("%d %d %d\n",t1,t2,choose[n]);
		F(j,1,n)
		{
			if(p[j][choose[j]] > p[j][t1] && t1 != j)
			{
				res[j] = i;
				choose[j] = t1;
			}
			else if(t1 == j && p[j][choose[j]] > p[j][t2] && t2 != j)
			{
				res[j] = i;
				choose[j] = t2;
			}
		}
	}
	F(i,1,n) printf("%d ",choose[i]);
	return 0;
}

