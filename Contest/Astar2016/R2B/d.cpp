#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int n,m;
int l[maxn],r[maxn];

bool yes(int d)
{
	int L = -INF,R = INF,LL = -INF,RR = INF;
	for(int i=0;i<m;++i)
	{
		if(r[i] - l[i] <= d) continue;
		L = max(L,l[i]+r[i]-d);
		R = min(R,l[i]+r[i]+d);
		LL = max(LL,l[i]-r[i]-d);
		RR = min(RR,l[i]-r[i]+d);
	}
	return L <= R && LL <= RR;
}

int solve()
{
	int l = 0,r = n,res = n;
	while(l <= r)
	{
		int m = (l+r)/2;
		if(yes(m))
		{
			res = m;
			r = m-1;
		}
		else l = m+1;
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d%d",&n,&m) == 2)
	{
		for(int i=0;i<m;++i)
		{
			scanf("%d %d",l+i,r+i);
			if(l[i] > r[i]) swap(l[i],r[i]);
		}
		printf("%d\n",solve());
	}
	return 0;
}
