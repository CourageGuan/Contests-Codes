//TLE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=30010;
typedef long long ll;
int n,k,m,save[maxn],block[maxn],map[2][maxn];
ll ans;

struct Query{
	int l,r,u,v,id;
	ll ans;
	Query(int l=0,int r=0,int u=0,int v=0,int id=0):l(l),r(r),u(u),v(v),id(id) {}
} q[maxn];

bool cmp(const Query& a,const Query& b){
	if(block[a.l]==block[b.l]) return a.r<b.r;
	return a.l<b.l;
}

bool cmp_id(const Query& a,const Query& b){
	return a.id<b.id;
}

void update(int id,int p,int add){
	if(k<=save[p]){
		map[id][save[p]]+=add;
		return;
	}
	ans-=(map[id][save[p]]*map[id^1][k-save[p]]);
	map[id][save[p]]+=add;
	ans+=(map[id][save[p]]*map[id^1][k-save[p]]);
}

void solve(){
	memset(map[0],0,sizeof map[0]);
	memset(map[1],0,sizeof map[1]);
	ll res=0;ans=0;
	int l=1,u=1,r=0,v=0;
	for(int i=1;i<=m;++i){
		for(;l<q[i].l;++l) update(0,l,-1);
		for(;l>q[i].l;--l) update(0,l-1,1);
		for(;r<q[i].r;++r) update(0,r+1,1);
		for(;r>q[i].r;--r) update(0,r,-1);

		for(;u<q[i].u;++u) update(1,u,-1);
		for(;u>q[i].u;--u) update(1,u-1,1);
		for(;v<q[i].v;++v) update(1,v+1,1);
		for(;v>q[i].v;--v) update(1,v,-1);
		q[i].ans=ans;
	}
	sort(q+1,q+m+1,cmp_id);
	for(int i=1;i<=m;++i) printf("%lld\n",q[i].ans);
}

int main() 
{
	//freopen("test.txt","r",stdin);
	while(~scanf("%d",&n)){
		scanf("%d",&k);
		for(int i=1;i<=n;++i) scanf("%d",save+i);
		scanf("%d",&m);	
		int l,r,u,v,N=(int)sqrt(n+0.5);
		for(int i=1;i<=m;++i) scanf("%d %d %d %d",&l,&r,&u,&v),q[i]=Query(l,r,u,v,i);
		for(int i=1;i<=n;++i) block[i]=(i-1)/N+1;
		sort(q+1,q+m+1,cmp);
		solve();
	}
	return 0;
}




