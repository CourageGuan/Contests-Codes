#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;++i) scanf("%d",a+i);
		int cnt = 1,res = 1;
		for(int i=1;i<n;++i)
		{
			if(a[i]>=a[i-1]) ++cnt;
			else cnt = 1;
			res = max(cnt,res);
		}
		printf("%d\n",res);
	}
	return 0;
}
