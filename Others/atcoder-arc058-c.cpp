#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int mod = 1e9 + 7;

const int maxn = 45;
const int maxm = (1<<17) + 10;

int d[maxn][maxm];
int n,x,y,z;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> x >> y >> z;
	int m = x+y+z;
	d[0][0] = 1;
	F(i,0,n-1)
	{
		F(s,0,1<<m)
		{
			if(!d[i][s]) continue;
			F(p,1,10)
			{
				if(s == 1<<m)
				{
					d[i+1][s] = (d[i+1][s] + d[i][s]) %mod;
					continue;
				}
				int msk = ((s << p) | (1 << (p-1))) & ((1<<m)-1);
			//	printf("%d\n",msk);
				if((msk & 1<<(x-1)) && (msk & 1<<(x+y-1)) && (msk & (1<<(x+y+z-1)))) msk = 1<<m;
				d[i+1][msk] = (d[i+1][msk] + d[i][s]) %mod;
			}
		}
	}
	printf("%d\n",d[n][1<<m]);
	return 0;
}
