#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100000 + 5;

int main()
{
	int n,a[maxn],b[maxn],c[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	for(int i=0;i<n-1;++i) scanf("%d",&b[i]);
	for(int i=0;i<n-2;++i) scanf("%d",&c[i]);
	sort(a,a+n);
	sort(b,b+n-1);
	sort(c,c+n-2);
	int i;b[n-1]=-1;
	for(i=0;i<n;++i) if(a[i]!=b[i]) break;
	printf("%d\n",a[i]);
	c[n-2]=-1;
	for(i=0;i<n-1;++i) if(c[i]!=b[i]) break;
	printf("%d\n",b[i]);
	return 0;
}
