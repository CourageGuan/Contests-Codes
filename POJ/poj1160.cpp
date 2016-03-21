//区间dp 四边形不等式
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxv = 310;
const int maxp = 40;
int d[maxv][maxv],K[maxv][maxv],p,v;
int save[maxv];
int w[maxv];

int getw(int l,int r)
{
	int m=(l+r)>>1;
	return w[r] - w[m] - (r-m)*save[m] + (m-l)*save[m] - (w[m-1]-w[l-1]);
}

int main()
{
    //freopen("test.txt","r",stdin);
	while(scanf("%d %d",&v,&p)==2)
	{
		w[0]=0;
		for(int i=1;i<=v;++i)
		{
		   	scanf("%d",save+i);
			w[i] = w[i-1] + save[i];
		}

		for(int i=0;i<=v;++i)
		{
            K[i][i]=i;
            d[i][i]=0;
		}

		for(int L=1;L<=v-p;++L)
		{
			int j;
			for(int i=0; (j=i+L)<=v;++i) d[i][j]=INF;
			for(int i=1; (j=i+L)<=v;++i)
			{
				int &res = d[i][j];
				res = INF;

				for(int k=K[i][j-1];k<=K[i+1][j];++k)
				{
					int t=d[i-1][k-1] + getw(k,j);
					if(t<res)
					{
						//printf("(%d,%d)..%d\n",i,j,t);
						res = t;
						K[i][j] = k;
					}
				}
			}
		}
		printf("%d\n",d[p][v]);
	}
	return 0;
}

