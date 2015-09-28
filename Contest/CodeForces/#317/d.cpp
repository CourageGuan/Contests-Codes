//我们先对数组排序，然后可以发现每次选取的元素必然是连续的一段，且贡献的值为所选元素尾减去首
//然后我们发现一组的长度只可能为 n/k+1 or n/k ，个数分别为 n%k 和 k-n%k 个
//然后再进行dp，d[i][j] 表示选i个长度为 n/k+1 和 j个 n/k 的组
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 300010;
int a[maxn];
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL d[5010][5010];
int n1,n2,t1,t2;

LL dp(int i,int j)
{
	if(i == 0 && j == 0) return 0;
	LL &ans = d[i][j];
	if(ans!=-1) return ans;
	ans = INF;
	if(i>0)
		ans = min(ans,dp(i-1,j) + a[i*t1 + j*t2] - a[(i-1)*t1 + j*t2 +1]);
	if(j>0)
		ans = min(ans,dp(i,j-1) + a[i*t1 + j*t2] - a[i*t1 + (j-1)*t2 +1]);
	return ans;
}

int main()
{
//	freopen("test.txt","r",stdin);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1);
	a[0] = 0;
	n1 = n%k,n2 = k - n%k,t1 = n/k+1,t2 = n/k;
//	printf("%d %d %d %d\n",n1,n2,t1,t2);
	memset(d,-1,sizeof d);
	printf("%lld\n",dp(n1,n2));
	return 0;
}
