#include<bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("test.txt","r",stdin);
	freopen("coding_contest_creation.txt","r",stdin);
	freopen("ans_a.txt","w",stdout);
	int T,n,lst,cur,res,cnt;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		res = 0;
		lst = -1; cnt = 0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&cur);
			int val = (cur - lst -1) / 10;
			if(lst == -1) val = 0;
//			printf("%d %d %d\n",lst,cur,cnt);
			if(lst >= cur || val + cnt >= 4)
			{
				res += 4;
				cnt = 1;
				lst = cur;
				continue;
			}
			lst = cur;
			cnt += val+1;
			if(cnt == 4)
			{
				lst = -1;
				res += 4;
				cnt = 0;
			}
		}
		if(cnt) res += 4;
		assert(!(res%4));
		printf("Case #%d: %d\n",z,res - n);
	}
	return 0;
}
