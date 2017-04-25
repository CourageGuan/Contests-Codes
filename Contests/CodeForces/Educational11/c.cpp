#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 3e5 + 10;
int p[maxn],d[maxn];
int n,k,a[maxn];

queue<int> q;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	int i = 0,ans = 0,l,r;
	q.push(0);
	while(i <= n)
	{
		if(!a[i]) q.push(i);
		if(q.size() > k+1) q.pop();
		if(i - q.front() > ans)
		{
			ans = i - q.front();
			l = q.front();
			r = q.back();
		}
		++i;
	}
	for(int i=l+1;i<=r;++i) a[i] = 1;
	printf("%d\n",ans);
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}
