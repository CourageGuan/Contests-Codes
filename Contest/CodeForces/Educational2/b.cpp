#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];
int n,m;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i =0;i<n;++i) scanf("%d",a+i);
	sort(a,a+n);
	for(int i =0;i<m;++i)
	{
		int b;
		scanf("%d",&b);
		int ans = upper_bound(a,a+n,b) - a;  
		printf("%d%c",ans,i == m-1?'\n':' ');
	}
	return 0;
}
