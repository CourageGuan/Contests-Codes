#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100000+5;

struct node{
	long long x,y;
	bool operator<(const node &b) const{
		return x<b.x;
	}
} a[maxn],b[maxn];

int main()
{
	//freopen("test","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int m,n;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;++i) scanf("%lld%lld",&a[i].x,&a[i].y);
		for(int i=0;i<m;++i) scanf("%lld%lld",&b[i].x,&b[i].y);
		sort(a,a+n);
		sort(b,b+m);
		for(int i=1;i<m;++i) b[i].y+=b[i-1].y;
		int j=0;long long ans=0;
		for(int i=0;i<n;++i){
			while(a[i].x>b[j].x){
				if ((j==m-1) || (j+1<m && a[i].x<=b[j+1].x)) break; 
				else ++j;
			}
			if(j>=m) break;
			if(a[i].x<=b[j].x) continue;
			//cout<<a[i].x<<" "<<b[j].x<<endl;
			ans+=a[i].y*b[j].y;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


