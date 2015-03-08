//hashmap 值得借鉴
#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;

typedef long long ll;
const int maxn=1000000 + 1000;
int a[maxn];

const unsigned long long Mod=1000007;

struct hashmap{
    struct Edge
    {
        long long num;
        int next;
    };
    Edge edge[maxn<<1];
    int countedge;
    int head[Mod+100];

    void init()
    {
        memset(head,-1,sizeof(head));
        countedge=0;
    }

    void addedge(long long num)
    {
        int start=num%Mod;
        edge[countedge].next=head[start];
        edge[countedge].num=num;
        head[start]=countedge;
        countedge++;
    }

    int Find(long long num)
    {
        int start=num%Mod;
        int ind;
        for(ind=head[start]; ind!=-1; ind=edge[ind].next)
        {
            if(edge[ind].num==num)break;
        }
        return ind;
    }
}hash1,hash2;


/*
ll sum(int l,int r)
{ 
  if(l==r) return a[l];
  if(r-l==1) return a[l]-a[r];
  int code=(l&1)?1:0;
  return p[code][r+1]-p[code][l];
}*/


int main()
{
	int T,n;
	ll k;
	scanf("%d ",&T);
	for(int kase=1;kase<=T;++kase){
		hash1.init();
		hash2.init();
		scanf("%d %lld",&n,&k);
		bool flag=false;
		ll s=0;hash1.addedge(0);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			if(i&1) s-=a[i];
			else s+=a[i];
			if(!flag){
				if(hash1.Find(s-k)!=-1) flag=true;
				if(hash2.Find(s+k)!=-1) flag=true;
			} else continue;
			if(i&1) hash1.addedge(s);
			else hash2.addedge(s);
		}
		printf("Case #%d: %s\n",kase,flag?"Yes.":"No.");
	}
	return 0;
}

