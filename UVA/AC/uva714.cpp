/*二分答案，记得开ll...*/
#include<bits/stdc++.h>
using namespace std;

#define max(a,b) a>b?a:b
#define F(i,a,b) for(ll i=a;i<=b;++i)
#define Fd(i,a,b) for(ll i=a;i>=b;--i) 
#define pb push_back
typedef long long ll;

const ll maxn=500+5;
int m,k,v[maxn];


ll p(ll now)
{
	ll i=m-1,cnt=0;
	ll res=0;
	while(i>=0){
		ll cur=0;
		cur+=v[i];i--;
		while(cnt==k || cur+v[i]<=now){
			if(i+1<k-cnt) break;
			cur+=v[i];i--;
		}
		res=max(res,cur);
		cnt++;
		//cout<<cur<<endl;
	}
	return res;
}


void solve(ll l,ll r)
{
	while(l<r){
		ll mid=l+(r-l)/2;
		if(p(mid)<=mid) r=mid;
		else l=mid+1;
		//cout<<l<<" "<<r<<" "<<mid<<" "<<p(mid)<<endl;
	}
	l=p(l);
	//cout<<l<<" "<<p(l)<<endl;
	ll rec[maxn];
	ll i=m-1;
	ll cur,cnt=0;
	while(cnt<k){
		cur=0;
		cur+=v[i];i--;
		if(i>=k-cnt){
			while(cur+v[i]<=l){
				cur+=v[i];i--;
				if(i<k-cnt) break;
			}
		}
		rec[cnt++]=i;
	}
	cnt=k-1;
	F(i,0,m-1){
		if(i) printf(" ");
		printf("%d",v[i]);
		if(rec[cnt]==i){
			printf(" /");
			cnt--;
		}
	}
	printf("\n");
}


int main()
{
	//freopen("test","r",stdin);
	//freopen("1","w",stdout);
	int kase;
	cin>>kase;
	while(kase--){
		ll l=0,r=0;
		cin>>m>>k;
		--k;
		F(i,0,m-1){
			scanf("%d",&v[i]);
			l=max(l,v[i]);
			r+=v[i];
		}
		solve(l,r);
	}
	return 0;
}

