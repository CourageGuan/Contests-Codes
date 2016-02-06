#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int n;
LL a[maxn],b[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	LL sum = 0;
	for(int i=0;i<n;++i) scanf("%lld",a+i),sum += a[i];
	int cnt = 0;
	b[0] = 0;
	for(int i=0;i<n;++i) if(a[i]&1) b[cnt++] = a[i];
	sort(b,b+cnt);
	if(cnt&1) sum -= b[0];
	printf("%lld\n",sum);
	return 0;
}
