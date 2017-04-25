#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 100;
int a[maxn][4];
int n,m;

int main()
{
//	freopen("test.txt"."r",stdin);
	cin >> n >> m;	
	for(int i=0;i<n;++i)
	{
		if(2*i+1 <= m) a[i][0] = 2*i+1;
		if((2*(i+n))+1 <= m) a[i][1] = (2*(i+n))+1;
		if((2*(i+n))+2 <= m) a[i][2] = (2*(i+n))+2;
		if(2*i+2 <= m) a[i][3] = 2*i+2;

//		for(int j=0;j<4;++j) printf("%d ",a[i][j]);
//		puts("");
	}
	for(int i=0;i<n;++i)
	{
		if(a[i][1]) printf("%d ",a[i][1]);
		if(a[i][0]) printf("%d ",a[i][0]);
		if(a[i][2]) printf("%d ",a[i][2]);
		if(a[i][3]) printf("%d ",a[i][3]);
	}
	puts("");
	return 0;
}
