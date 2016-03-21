//直接2^n暴力
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;

const int maxn = 22;

double l[maxn],a[maxn],b[maxn];


inline double cal(double a,double b)
{
	return (a-b)*(a-b);
}

int time(int t)
{
	int cnt = 0;
	while(t)
	{
		if(t&1) ++cnt;
		t>>=1;
	}
	return cnt;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	while(scanf("%d %d",&n,&m)==2)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%lf %lf %lf",l+i,a+i,b+i);
		}
		double ans = 0;
		for(int i=0;i<(1<<n);++i)
		{
			if(time(i)!=m) continue;
			vector<int> item;
			for(int j=0 ; (1<<j) <i; ++j)
			{
				if(i&(1<<j)) item.push_back(j);
			}
			double res = 0;
			for(int j=0;j<m;++j)
			{
				for(int t = j+1;t<m;++t)
				{
					res += cal(b[item[j]],b[item[t]])+cal(a[item[j]],a[item[t]])+cal(l[item[j]],l[item[t]]);
				}
			}
			ans = max(ans,res);
		}
		printf("%lf\n",ans);
	}
	return 0;
}

