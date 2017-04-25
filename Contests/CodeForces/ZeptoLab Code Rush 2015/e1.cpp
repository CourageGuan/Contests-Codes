#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;

const int N = 2000010;

int a[N], to[N];
ll p[N];

int main() 
{
	//freopen("test","r",stdin);
	int n,q;
	ll sum=0;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
		a[i+n]=a[i];
		sum+=a[i];
	}
	int j=0;
	while(q--){
		ll t,cur=0;
		scanf("%lld",&t);
		if(t>=sum){
			puts("1");
			continue;
		}
		int j=0,len=n,st=0,cnt=0;
		for(int i=0;i<n;++i){
			while(j<2*n && a[j]+cur<=t) cur+=a[j++];
			to[i]=j;
			cur-=a[i];
			if(to[i]-i<len) len=to[i]-i,st=i;
			++cnt;
		}
		for(int i=0;i<n;++i){ if(to[i]>=n){
		   	to[i]-=n;
		}
		//cout<<i<<" "<<to[i]<<endl;
		}
		int ans=cnt;
		for(int i=st;i<=st+len;++i){
			if(i>=n) i-=n;
			int j=i;
			cnt=0;
			bool flag=false;
			while(1){
				j=to[j];
				++cnt;
				//cout<<j<<endl;
				if(flag && j>=i) break;
				if(to[j]<j) flag=true;
			}
			ans=min(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}

