#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=20000 + 5;

int main()
{
	//freopen("test","r",stdin);
	int m,n,a[maxn],b[maxn];
	while(scanf("%d %d",&n,&m) && n){
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		for(int i=0;i<m;++i) scanf("%d",&b[i]);
		if(m<n){
			puts("Loowater is doomed!");
			continue;
		}
		sort(a,a+n);
		sort(b,b+m);
		int cnt=n,j=0;
		long long waste=0;
		for(int i=0;i<m;++i){
			if(j>=n) break;
			if(b[i]>=a[j]){
				//cout<<a[i]<<" "<<b[j]<<endl;
				++j;
				--cnt;
				waste+=b[i];
			}
		}
		if(cnt) puts("Loowater is doomed!");
		else printf("%lld\n",waste);
	}
	return 0;
}

