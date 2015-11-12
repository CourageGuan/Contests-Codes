#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10;
struct P
{
	int l,r;
	bool operator<(const P& rhs) const
	{
		return r < rhs.r || (r == rhs.r && l > rhs.l);
	}
} save[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d %d",&save[i].l,&save[i].r);
	sort(save,save+n);
	int last = -1,cnt = 0;
	for(int i=0;i<n;++i)
	{
		if(save[i].l > last)
		{
			last = save[i].r;
			++cnt;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
