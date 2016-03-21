#include<bits/stdc++.h>
using namespace std;

const int maxn = 300010;
char s[maxn];
map<int,int> range;
map<int,int>::iterator it;

int main()
{
	//freopen("test.txt","r",stdin);
	int n,q;
	while(scanf("%d %d",&n,&q)==2)
	{
		range.clear();
		scanf("%s",s);
		int ans = 0,cur = 0;
		for(int i=0;i<n;++i)
		{
			if(s[i]!='.')
			{
				if(cur) ans += cur - 1;
				cur = 0;
				range[i+1] = 1;
			}
			else ++cur;
		}
		range[0] = 1;
		range[n+1] = 1;
		if(cur) ans += cur - 1;
		while(q--)
		{
			int i,op;
			char ss[2];
			scanf("%d %s",&i,ss);
			op = (ss[0] != '.');
			if(range.count(i)==op)
			{
				printf("%d\n",ans);
				continue;
			}
			if(!op) range.erase(i);
			it = range.lower_bound(i);
			--it;
			int low = it->first;
			it = range.upper_bound(i);
			int high = it->first;
//			printf("%d .. %d %d\n",i,low,high);
			if(op)
			{
				ans -= max(0,(high-low-2));
				ans += max(0,(high -i-2));
				ans += max(0,(i- low- 2));
			}
			else
			{
				ans -= max(0,(high - i-2));
				ans -= max(0,(i- low - 2));
				ans += max(0,(high-low-2));
			}
			if(op) range[i] = 1;
			printf("%d\n",ans);
		}
	}
	return 0;
}
