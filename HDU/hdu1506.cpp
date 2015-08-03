//一道经典的问题，在一些长度不一的长条序列中找一块最大的矩形
//从两侧扫描两次，用单调队列维护当前高度可以向左(右)的延伸值
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long LL;
const int maxn = 100010;
int high[maxn];
int l[maxn],r;
int q[maxn*2],h,t;

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1 && n)
	{
		q[0] = -1;
		h = 1;
		t = 1;
		for(int i = 0;i<n;++i)
		{
			scanf("%d",high+i);
			while(h<t && high[q[t-1]] >= high[i]) --t;
			l[i] = i - q[t-1];
			q[t++] = i;
		}
		q[0] = n;
		h = 1;
		t = 1;
		LL ans = 0;
		for(int i = n-1;i>=0;--i)
		{
			while(h<t && high[q[t-1]] >= high[i] ) --t;
			r = q[t-1] - i;
			q[t++] = i;
//			printf("%d %d\n",i,r);
			ans = max(((LL)high[i]*(r+l[i]-1)),ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

