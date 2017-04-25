#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 110;
int a[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int ans = 0,rem = -1;
	memset(a,0,sizeof a);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<n;++i)
	{
		if(a[i] == 1) ++ans;
		if(a[i] == 0 && i && a[i-1] == 1 && a[i+1] == 1) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
