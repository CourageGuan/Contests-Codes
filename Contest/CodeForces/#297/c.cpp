#include<bits/stdc++.h>
using namespace std;

const int maxn=100000 + 10;
typedef long long ll;
int a[maxn];
ll res[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	sort(a,a+n);
	int i,cnt=0;
	memset(res,0,sizeof(res));
	for(i=n-1;i>0;--i){
		if(a[i]==a[i-1] || a[i]==a[i-1]+1){
			res[cnt++]=a[i-1];
			--i;
		}
	}
	ll ans=0;
	for(int i=0;i<cnt;i+=2) ans+=res[i]*res[i+1];
	printf("%lld\n",ans);
	return 0;
}
