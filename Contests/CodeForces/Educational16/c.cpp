#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 50;
int n,cur,d[maxn][maxn];

bool check()
{
	int sum;
	F(i,1,n)
	{
		sum = 0;
		F(j,1,n)
		{
			sum += d[i][j];
			if(d[i][j] > n*n) return 0;
		}
		if(!(sum&1)) return 0;
		sum = 0;
		F(j,1,n) sum += d[j][i];
		if(!(sum&1)) return 0;
	}
	sum = 0;
	F(i,1,n) sum += d[i][i]; 
	if(!(sum&1)) return 0;

	sum = 0;
	F(i,1,n) sum += d[n-i+1][i]; 
	if(!(sum&1)) return 0;

	return 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	//	for(int z=1;z<50;z+=2)
	//	{
	scanf("%d",&n);
	fill(d,0);
	cur = -1;
	F(i,1,n) d[i][(n+1)/2] = cur += 2;
	F(i,1,n) if(i != (n+1)/2) d[(n+1)/2][i] = cur += 2;
	int rem = (n*n/2 - 2*n + 2)/4,t = n - 2;
	while(rem)
	{
		if(rem < t) 
		{
			t -= 2;
			continue;
		}
		int l = (n - 2 - t)/2;
		F(j,1+l,n-l)
		{
			if(j == (n+1)/2) continue;
			d[1 + l][j] = cur += 2;
			d[n - l][j] = cur += 2;
			if(j == 1+l || j == n-l) continue;
			d[j][1 + l] = cur += 2;
			d[j][n - l] = cur += 2;
		}
		rem -= t;
		t -= 2;
	}
	cur = 0;
	F(i,1,n) F(j,1,n)
		if(!d[i][j]) d[i][j] = cur += 2;

	F(i,1,n)
	{
		F(j,1,n)
		{
			printf("%d ",d[i][j]);
		}
		puts("");
	}
	//}
	return 0;
}

