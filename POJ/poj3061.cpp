//求和大于等于S的最短区间
//滑动窗口
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100010;
const int INF = 0x3f3f3f3f;
int save[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T,n,S;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&S);
		for(int i=0;i<n;++i) scanf("%d",save+i);
		int i,j; i = j = 0;
		int ans = INF,now = 0;
		while(j<n)
		{
			while(j<n && now<S)
			{
				now += save[j++];
			}
			while(i<n && now>=S)
			{
				flag = true;
				ans = min(ans,j-i);
				now -= save[i++];	
			}
		}
		if(ans == INF) puts("0");
		else printf("%d\n",ans);
	}
	return 0;
}


