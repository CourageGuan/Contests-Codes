#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n,m,l;
int a[maxn],b[maxn],c[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&l);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<m;++i) scanf("%d",b+i);
	for(int i=0;i<l;++i) scanf("%d",c+i);
	sort(b,b+m);
	sort(c,c+l);
	LL ans = INF;
	for(int i=0;i<n;++i)
	{
		int ta = i;
		int tb = lower_bound(b,b+m,a[ta]) - b;
		int tc = lower_bound(c,c+l,a[ta]) - c;
		if(tb >= m) --tb;
		if(tc >= l) --tc;
		ans = min(ans,0LL+abs(a[ta]-b[tb]) + abs(a[ta]-c[tc]) + abs(b[tb]-c[tc]));
		if(tb-1>=0) ans = min(ans,0LL+abs(a[ta]-b[tb-1]) + abs(a[ta]-c[tc]) + abs(b[tb-1]-c[tc]));
		if(tc-1>=0) ans = min(ans,0LL+abs(a[ta]-b[tb]) + abs(a[ta]-c[tc-1]) + abs(b[tb]-c[tc-1]));
		if(tb-1>=0 && tc-1>=0)ans = min(ans,0LL+abs(a[ta]-b[tb-1]) + abs(a[ta]-c[tc-1]) + abs(b[tb-1]-c[tc-1]));
	}
	printf("%lld\n",ans);
	return 0;
}
