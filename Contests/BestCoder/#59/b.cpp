//通过观察不难发现对每个数最多操作一次
//选定一个无序集合必定可以使之排列有序
//我们发现若小的元素在大的前面那么这个大的元素就不用选择。
//从n开始向前找不用选择的元素个数cnt
//最后减去这个个数即可
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int maxn = 20;
int save[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int p = 0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",save+i);
			if(save[i] == n) p = i;
		}
		int cnt = 1;
		int cur = n - 1;
		while(--p >= 0)
		{
			if(save[p] == cur)
			{
				++cnt;
				--cur;
			}
		}
		printf("%d\n",n-cnt);
	}
	return 0;
}
