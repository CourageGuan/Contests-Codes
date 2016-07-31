#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;

int n,m,l,r;
int t[maxn],q[maxn];
LL sum[maxn];
DB p[maxn],rev[maxn],d[55][maxn];

DB up(int t,int k,int j)
{
	return d[t][j] - d[t][k] + p[k] - p[j] + sum[j]*rev[j] - sum[k]*rev[k];
}

DB down(int k,int j)
{
	return sum[j] - sum[k];
}

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m;
	F(i,1,n) scanf("%d",t+i),sum[i] = sum[i-1] + t[i],rev[i] = rev[i-1] + 1.0/t[i],p[i] = p[i-1] + 1.0*sum[i]/t[i],d[1][i] = p[i];
	F(j,2,mk
	{
		l = r = 0;
		q[r++] = 0;
		F(i,1,n)
		{
			while(l + 1 < r && up(j-1,q[l],q[l+1]) < rev[i]*down(q[l],q[l+1])) ++l;
			int k = q[l];
			d[j][i] = d[j-1][k] + p[i] - p[k] - sum[k]*(rev[i] - rev[k]);
			while(l + 1 < r && up(j-1,q[r-2],q[r-1])*down(q[r-1],i) >= up(j-1,q[r-1],i)*down(q[r-2],q[r-1])) --r;
			q[r++] = i;
		}
	}
	printf("%.8lf\n",d[m][n]);
	return 0;
}
