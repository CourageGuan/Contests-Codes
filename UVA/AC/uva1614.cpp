/*贪心，首先sum必须为偶数,排序后从后向前若不大于sum/2  s1+=a[i].v
 * 可以证明若满足s1==sum/2则得到解,若无法找到s1==sum/2则无解
 * 简要证明: 对于目前已选元素，若剩下元素存在可以与之匹配的解，则肯定可以得到对应解
 * 因为每加入一个解s1总<=sum/2*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const long long maxn=100000 + 5;

struct node{
	long long id,v;
	bool b;
	bool operator<(const node& b) const {
		return v<b.v;
	}
} a[maxn];

 bool cmp(const node& a,const node& b) {
	return a.id<b.id;
}

int main()
{
	//freopen("test","r",stdin);
	long long n;
	while(scanf("%lld",&n)==1){
		long long sum=0,s1;
		for(long long i=0;i<n;++i){
			scanf("%lld",&a[i].v);
			a[i].id=i;a[i].b=0;
			sum+=a[i].v;
		}
		if(sum&1){
			puts("No");
			continue;
		}
		sort(a,a+n);
		sum/=2;s1=0;
		for(long long i=n-1;i>=0;--i){
			if(s1+a[i].v<=sum){
				s1+=a[i].v;
				a[i].b=1;
				if(s1+a[i].v==sum) break;
			}
		}
		if(s1!=sum){
			puts("No");
			continue;
		}
		sort(a,a+n,cmp);
		puts("Yes");
		for(long long i=0;i<n;++i){
			if(i) printf(" ");
			printf("%d",a[i].b?1:-1);
		}
		puts("");
	}
	return 0;
}


