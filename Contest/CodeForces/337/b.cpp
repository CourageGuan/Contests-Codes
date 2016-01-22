#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 4e5 + 10;
const int INF = 0x3f3f3f3f;
int a[maxn],n;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);	
	int mn = INF;
	for(int i=0;i<n;++i) scanf("%d",a+i),a[i+n] = a[i],mn = min(mn,a[i]);
	int len = 0,lst = -1;
	for(int i=0;i<2*n;++i)
	{
		if(a[i] == mn)
		{
			len = max(len,i - lst-1);
			lst = i;
		}
	}
	printf("%lld\n",(LL)mn*n+(LL)len);
	return 0;
}
