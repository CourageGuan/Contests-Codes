#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

vector<int> ans;

bool yes(LL n)
{
	for(int k=2;k<=10;++k)
	{
		bool flag = false;
		LL t = 0;
		for(int j=15;j>=0;--j)
			t = t*k + ((n>>j)&1);
		int m = min((int)(sqrt(t)+1),1007);
		for(int i=2;i<=m;++i)
			if(t%i == 0)
			{
				ans.push_back(i);
				flag = true;
				break;
			}
		if(!flag) return false;
	}
	return true;
}

int main()
{
	freopen("ansC.txt","w",stdout);
	puts("Case #1:");
	int n = 16,j = 50;
	for(int i=0;i<(1<<14);++i)
	{
		LL t = (i<<1) + 1 + (1<<15);
		if(yes(t))
		{
			--j;
			for(int z=15;z>=0;--z) putchar((t&(1<<z))?'1':'0');
			putchar(' ');
			for(int z=0;z<ans.size();++z) printf("%d ",ans[z]);
			puts("");
		}
		ans.clear();
		if(!j) break;
	}
	return 0;
}

