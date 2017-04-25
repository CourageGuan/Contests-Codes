//3n(n-1)+1 = 6(n(n-1)/2) + 1
//n(n-1)/2 为三角形数 任何一个自然数都可以表示为三个(或以上)三角形数的和
//因此假设m由k个数组成  m = 6k(k个三角形数的和) + k (k>=3) 确定 (m-k)%6=0  的最小k即可注意k>=3
//但是 k=1 和 k=2 时需要讨论 m是否可以由一个 和 两个数表示，如果不可以则 k = 7 k = 8
//还要注意 k = 0 时 取 k=6
#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;

const int maxn = 20010;
int ans,n,m;
int a[maxn];

void init()
{
	n = 0;
	a[0] = 0;
	for(n=1;;++n)
	{
		a[n] = 3*n*(n-1) + 1;
		if(a[n]>1e9) break;
	}
}

int solve()
{
	int k = m%6;
	if(k == 0) k+=6;
	if(k>2) return k;
	if(k == 1)
	{
		int t = lower_bound(a,a+n,m) - a;
		if(a[t] == m) return 1;
		else return 7;
	}
	else{
		for(int i = 1;i <n;++i)
		{
			if(a[i] >= m) break;
			int t = lower_bound(a,a+n,m-a[i]) - a;
			if(a[t] == m-a[i]) return 2;
		}
		return 8;
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	init();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&m);
		printf("%d\n",solve());
	}
	return 0;
}
