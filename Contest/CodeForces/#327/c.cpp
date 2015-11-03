#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 5e5 + 10;
bool a[maxn],b[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d%*c",&n);
	for(int i=1;i<=n;++i)
	{
		a[i] = getchar() - '0';
		getchar();
	}
	int ans = 0;
	a[0] = a[1];
	a[n+1] = a[n];
	for(int i=1;i<=n;)
	{
		if(a[i] == a[i-1] && a[i]!=a[i+1])
		{
			int cnt = 1,p = i;
			while(a[i+1] != a[i])
			{
				++i;
				++cnt;
			}
			ans = max(ans,(cnt-1)/2);
			if(cnt&1) for(int j=p;j<=i;++j) b[j] = a[p];
			else
			{
				for(int j=p;j<=p+cnt/2;++j) b[j] = a[p];
				for(int j=p+cnt/2;j<=i;++j) b[j] = a[p]^1;
			}
		}
		else
		{
			b[i] = a[i];
			++i;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i) printf("%c%c",b[i]?'1':'0',i==n?'\n':' ');
	return 0;
}
