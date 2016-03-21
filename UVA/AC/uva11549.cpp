//模拟判重 set 0.742s  hash 0.119s
//Floyd 判圈算法 0.219s   若存在一个环，则两个速度不同的指针一定会在环上相遇
#include<cstdio>
#include<iostream>
#include<cmath>
#include<set>
#include<cstring>
using namespace std;

typedef long long ll;
/*
//set<int> vis;

const int maxn=100000 + 10;
const long long mod=100007;

struct HashTable{
	struct Edge{
		long long num;
		int next;
	} edges[maxn<<1];
	int head[mod + 5];
	int size;

	void init()
	{
		memset(head,-1,sizeof(head));
		size=0;
	}

	void add(long long num)
	{
		int start=num%mod;
		edges[size].next=head[start];
		edges[size].num=num;
		head[start]=size;
		size++;
	}

	int find(long long num)
	{
		int start=num%mod;
		int pos;
		for(pos=head[start]; pos!=-1; pos=edges[pos].next) if(num==edges[pos].num) break;
		return pos;
	}
} vis;

int main()
{
	int t,n;
	ll k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %lld",&n,&k);
		vis.init();
		n=(int)pow(10,n);
		ll ans=k;
		vis.add(k);
		while(1){
			k*=k;
			while(k>=n) k/=10;
			ans=max(k,ans);
			if(vis.find(k)!=-1 || ans+1==n) break;
			vis.add(k);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
*/

int main()
{
	int t,n;
	ll k,k1,k2;
	scanf("%d",&t);
	while(t--){
		scanf("%d %lld",&n,&k);
		n=(int)pow(10,n);
		ll ans;
		ans=k1=k2=k;
		do{
			k1*=k1;
			while(k1>=n) k1/=10;
			k2*=k2;
			while(k2>=n) k2/=10;
			if(k2>ans) ans=k2;
			k2*=k2;
			while(k2>=n) k2/=10;
			if(k2>ans) ans=k2;
			if(ans==n-1) break;
		} while(k1!=k2);
		printf("%d\n",ans);
	}
	return 0;
}
