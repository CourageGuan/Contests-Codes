#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1e9+9;
const int maxn=100000 + 5;

ll qpow(ll a,ll n,ll m)
{
	if(n==0) return 1;
	ll x=qpow(a,n/2,m);
	ll res=x*x%m;
	if(n&1) res=res*a%m;
}

struct node{
	int x,y,id,pos;
	bool operator<(const node &b) const{
		if(y==b.y) return x<b.x;
		else return y>b.y;
	}
} p[maxn],q[maxn];

set<int> lis;
ll m;

void solve()
{
	for(int i=1;i<m;++i){
		if(p[i].id==-1) continue;
		int x=p[i].x,y=p[i].y;
		bool flag=true;
		for(int j=i-1;j>=0;--j){
			if(p[j].y-y>=2) break;
			if(p[j].id==-1) continue;
			if(abs(x-p[j].x)<=1 && y==p[j].y-1){
				flag=false;
				break;
			}
		}
		if(flag) lis.insert(p[i].id);
	}
}

ll mn()
{
	solve();
	int id=*(lis.begin());
	p[q[id].pos].id=-1;
	return id;
}

ll mx()
{
	solve();
	set<int>::iterator it=lis.end();
	it--;
	int id=(*it);
	p[q[id].pos].id=-1;
	return id;
}



int main()
{
	cin>>m;
	for(int i=0;i<m;++i){
		scanf("%d %d",&p[i].x,&p[i].y);
		q[i].x=p[i].x;
		q[i].y=p[i].y;
		q[i].id=p[i].id=i;
	}
	sort(p,p+m);
	for(int i=0;i<m;++i){
		p[i].pos=i;
		q[i].pos=i;
	}
	ll res;
	for(ll i=0;i<m;++i){
		res+=((i&1)?mn():mx())*qpow(m,i,mod);
		res%=mod;
	}
	cout<<res%mod<<endl;
	return 0;
}

