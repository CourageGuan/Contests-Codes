#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;
const int maxn = 100010;
int a[maxn];
int mx[maxn],mn[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<n;++i)
	{
		mx[i] = max(a[n-1]-a[i],a[i]-a[0]);
		if(i!=0 && i!=n-1) mn[i] = min(a[i]-a[i-1],a[i+1]-a[i]);
		else if(i!=n-1) mn[i] = a[i+1] - a[i];
		else mn[i] = a[i] - a[i-1];
		printf("%d %d\n",mn[i],mx[i]);
	}
	return 0;
}
