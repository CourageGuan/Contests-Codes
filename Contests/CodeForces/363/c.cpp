#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 110;
int d[maxn][3],n;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<3;++j) d[i][0] = max(d[i][0],d[i-1][j]);
		if(a == 1)
		{
			d[i][2] = max(d[i-1][0],d[i-1][1]) + 1;
		}
		if(a == 2)
		{
			d[i][1] = max(d[i-1][0],d[i-1][2]) + 1;
		}
		if(a == 3)
		{
			d[i][2] = max(d[i-1][0],d[i-1][1]) + 1;
			d[i][1] = max(d[i-1][0],d[i-1][2]) + 1;
		}
//		printf("%d %d %d\n",d[i][0],d[i][1],d[i][2]);
	}
	printf("%d\n",n-max(d[n][0],max(d[n][1],d[n][2])));
	return 0;
}
