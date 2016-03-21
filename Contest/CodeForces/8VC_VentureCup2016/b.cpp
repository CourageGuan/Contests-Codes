#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
int n,a[maxn],b[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	int pa=0,pb=0,cnt = 0;
	for(int i=0;i<n;++i) scanf("%d",a+i),pa = a[i]==1?i:pa;
	for(int i=0;i<n;++i) scanf("%d",b+i),pb = b[i]==1?i:pb;
	while(cnt < n-1)
	{
		if(a[pa] != b[pb])
		{
			puts("NO");
			return 0;
		}
		++cnt;
		++pa;
		++pb;
		pa%=n;
		pb%=n;
		if(a[pa] == 0) ++pa;
		if(b[pb] == 0) ++pb;
		pa%=n;
		pb%=n;
	}
	puts("YES");
	return 0;
}
