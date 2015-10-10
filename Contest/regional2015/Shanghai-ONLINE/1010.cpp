#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
const int maxn = 110;
const int maxl = 100010;
int l[maxn],r[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		int n,a,b,L;
		scanf("%d%d%d%d",&n,&a,&b,&L);
		for(int i=0;i<n;++i) scanf("%d %d",l+i,r+i);
		int mn =0,cur = 0,lst = 0;
		for(int i=0;i<n;++i)
		{
			cur += (l[i] - lst)*b;
			cur -= (r[i] - l[i]) *a;
			lst = r[i];
			mn = min(mn,cur);
		}
		int ans = min(mn,cur);
		printf("Case #%d: %d\n",z,-ans);
	}
	return 0;
}

