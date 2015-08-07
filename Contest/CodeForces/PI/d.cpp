#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long LL;
#define pb push_back
const int maxn = 200010;
int n,k,a,m;
int save[maxn];

map<int,int> range;
map<int,int>::iterator it;

int solve()
{
	range.clear();
	range[0] = 1;
	range[n+1] = 1;
	int ans = (n+1)/(a+1);
	for(int i=1;i<=m;++i)
	{
		it = range.lower_bound(save[i]);
		--it;
		int low = it->first;
		it = range.upper_bound(save[i]);
		int high = it->first;
	//	printf("%d %d\n",low,high);
		ans -= (high - low)/(a+1);
		ans += (high - save[i])/(a+1);
		ans += (save[i] - low)/(a+1);
		if(ans < k)
		{
			return i;
		}
		range[save[i]] = 1;
	}
	return -1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d",&n,&k,&a,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",save+i);
	printf("%d\n",solve());
	return 0;
}


