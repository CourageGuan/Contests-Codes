#include<cstdio>

typedef long long ll;
const int maxn=60 + 5;

ll f(int p[],int k,int to)	//当前各圆盘位置  移动第k个圆盘 要移动到的位置
{
	if(k==0) return 0;
	if(p[k]==to) return f(p,k-1,to);
	return f(p,k-1,6-p[k]-to)+ (1LL<<(k-1));
}

int s[maxn],t[maxn];

int main()
{
	int n,kase=0;
	while(scanf("%d",&n) && n){
		for(int i=1;i<=n;++i) scanf("%d",&s[i]);
		for(int i=1;i<=n;++i) scanf("%d",&t[i]);
		int k=n;
		while(k && s[k]==t[k]) --k; 
		ll ans=0;
		if(k){
			int other=6-s[k]-t[k];
			ans=f(s,k-1,other)+f(t,k-1,other)+1;
		}
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}
