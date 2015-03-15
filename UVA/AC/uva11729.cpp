//贪心，尽量使时间长的j先执行，假定一条时间轴
//证明: 若按上述要求排列，任意交换两个元素，情况不会更优(时间长的会在轴上变得更长)
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1000 + 5;

struct Soldier{
	long long b,j;
	bool operator<(const Soldier & rhs) const {
		return j>rhs.j;
	}
} s[maxn];

int main()
{
	int n,kase=0;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i) scanf("%lld %lld",&s[i].b,&s[i].j);
		sort(s,s+n);
		long long ans=s[0].b+s[0].j;
		for(int i=1;i<n;++i){
			s[i].b+=s[i-1].b;
			ans=max(ans,s[i].b+s[i].j);
		}
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}
