//比较绕，k出现f(k)次 比如  1出现1次  2出现2次  3出现f(3)=2次  4出现f(4)=3次 ...
//设g(k) 为k最后一次出现的位置则   g(1)=1 g(2)=2  g(k)=g(k-1)+min(g(i)); // 设 g(i-1)<k<=g(i) (i>1)
//然后答案用二分查找第一个小于等于n的元素即为k
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn=1000000;

ll g[maxn+1];


int main()
{
	g[1]=1;
	g[2]=3;
	for(int i=3;i<maxn;++i)
		g[i]=g[i-1]+(lower_bound(g+1,g+i,i)-g);
	ll n;
	while(scanf("%lld",&n) && n)
		printf("%ld\n",(lower_bound(g+1,g+maxn,n)-g));
	return 0;
}
