//TLE
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long ll;
const int maxn=1000000;
int n,mx;
int m;
int e[maxn];
vector<int> primes;

void init(){
	bool vis[maxn+7];
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=(int)sqrt(maxn+0.5);++i) if(!vis[i])
		for(int j=i*i;j<=maxn;j+=i) vis[j]=1;
	for(int i=2;i<=maxn;++i) if(!vis[i]) primes.push_back(i);
}

void add_integer(int n,int d)
{
	for(int i=0;i<primes.size();++i){
		while(n%primes[i]==0){
			n/=primes[i];
			e[i]+=d;
			if(e[i]) mx=max(mx,i);
		}
		if(n==1) break;
	}
}

vector<int> pm;
int em[maxn];
void dealm(int m)
{
	memset(em,0,sizeof(em));
	pm.clear();
	for(int i=0;i<primes.size();++i){
		while(m%primes[i]==0){
			m/=primes[i];
			++em[i];
		}
		if(em[i]) pm.push_back(i);
		if(m==1) break;
	}
}

bool judge(int m)
{
	bool flag=true;
	for(int i=0;i<pm.size();++i)
		if(e[pm[i]]<em[pm[i]]){
			flag=false;
			break;
		}
	return flag;
}

void solve()
{
	dealm(m);
	if(n==1 || pm.size()==0){
		printf("0\n\n");
		return;
	}
	memset(e,0,sizeof(e));
	mx=0;n-=1;
	vector<int> ans;
	ll cur=1;
	for(int k=1;k<=n;++k){
		add_integer(n-k+1,1);
		add_integer(k,-1);
		if(judge(m)) ans.push_back(k+1);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i){
		if(i) printf(" ");
		printf("%d",ans[i]);
	}
	puts("");
}

int main()
{
	init();
	while(scanf("%d %lld",&n,&m)==2) solve();
	return 0;
}

