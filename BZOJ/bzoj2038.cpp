//莫队算法,区间查询与分块
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define P(n) n*n
typedef long long ll;
const int maxn=50010;
int save[maxn],map[maxn],block[maxn];
int n,m;
ll ans;

struct Query{
	int l,r,id;
	ll ans;
	Query(int l=0,int r=0,int id=0):l(l),r(r),id(id) {}
} q[maxn];


bool cmp1(const Query& a,const Query& b){ 	//根据左节点位置分块排序
	if(block[a.l]==block[b.l]) return a.r<b.r;	//在同一块中
	return a.l<b.l;		//不在同一块中
}

bool cmp2(const Query& a,const Query& b){ 
	return a.id<b.id;
}

ll gcd(ll a,ll b){
	return !b?a:gcd(b,a%b);
}

void update(int p,int add){
	ans-=P(map[save[p]]);
	map[save[p]]+=add;
	ans+=P(map[save[p]]);
}

void solve(){
	memset(map,0,sizeof map);
	int l=1,r=0; 
	ans=0;
	for(int i=1;i<=m;++i){
		for(;r<q[i].r;++r) update(r+1,1);
		for(;r>q[i].r;--r) update(r,-1);
		for(;l>q[i].l;--l) update(l-1,1);
		for(;l<q[i].l;++l) update(l,-1);
		if(q[i].l==q[i].r) q[i].ans=0;
		else q[i].ans=ans;
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	//freopen("hose.in","r",stdin);
	//freopen("hose.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",save+i);
	for(int i=1;i<=m;++i){
		int l,r;
		scanf("%d %d",&l,&r);
		q[i]=Query(l,r,i);
	}
	int N=(int)sqrt(m+0.5);
	for(int i=1;i<=n;++i) block[i]=(i-1)/N+1; 	//分块大法好
	sort(q+1,q+m+1,cmp1);
	solve();
	sort(q+1,q+m+1,cmp2);
	for(int i=1;i<=m;++i){
		ll mo=(ll)(q[i].r-q[i].l+1)*(q[i].r-q[i].l),so=q[i].ans-q[i].r+q[i].l-1;
		//cout<<q[i].l<<" "<<q[i].r<<" "<<q[i].ans<<endl;
		if(!so) puts("0/1");
		//else printf("%lld/%lld\n",so,mo);
		else printf("%lld/%lld\n",so/gcd(so,mo),mo/gcd(so,mo));
	}
	return 0;
}

