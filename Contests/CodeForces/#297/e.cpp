#include<bits/stdc++.h>
using namespace std;

#define min(a,b) ((a)<(b))?(a):(b)

typedef unsigned long long ll;
const ll fac[]={
0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000
};
const  ll INF=2e16;

map<ll,ll> has1[30];
map<ll,ll> has2[30];
map<ll,ll>::iterator it;
vector<int> a;
int n,k;
ll s;

int main()
{
	//freopen("test.txt","r",stdin);
	cin>>n>>k>>s;
	for(int i=0;i<n;++i){
		int t;
		scanf("%d",&t);
		if(t<=s) a.push_back(t);
	}
	for(int i=0;i<30;++i){
	   	has1[i].clear();
	   	has2[i].clear();
	}
	int m=a.size();
	int p1=m/2,p2=m-p1;
	int m1=1<<p1,m2=1<<p2;

	for(int bit=0;bit<m1;++bit)
		for(int tbit=bit;;tbit=(tbit-1)&bit){
			ll sum=0,tot=0;
			for(int i=0;i<p1;++i)
				if(bit&(1<<i)){
					if(tbit&(1<<i)){
						++tot;
						if(a[i]<20) sum+=fac[a[i]];
						else sum+=INF;
					}else sum+=a[i];
				}
			if(sum<=s) has1[tot][sum]++;
			if(!tbit) break;
		}

	for(int bit=0;bit<m2;++bit)
		for(int tbit=bit;;tbit=(tbit-1)&bit){
			ll sum=0,tot=0;
			for(int i=0;i<p2;++i)
				if(bit&(1<<i)){
					if(tbit&(1<<i)){
						++tot;
						if(a[i+p1]<20) sum+=fac[a[i+p1]];
						else sum+=INF;
					}else sum+=a[i+p1];
				}
			if(sum<=s) has2[tot][sum]++;
			if(!tbit) break;
		}
    ll ans=0;
	for(int i=0;i<=k;++i)
		for(it=has2[i].begin();it!=has2[i].end();++it){
			for(int t=0;t+i<=k;++t)
				if(s>=(it->first))
					ans+= it->second*has1[t][s-(it->first)];
		}
	cout<<ans<<endl;
	return 0;
}



