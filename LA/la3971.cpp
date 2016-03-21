//二分答案
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

typedef long long ll;

const int maxn=1000 + 5;
int n,b,type,maxq;
map<string,int> id;

int ID(string s)
{
	if(!id.count(s)) id[s]=type++;
	return id[s];
}

struct Device{
	int p;
	int q;
	Device(int p,int q): p(p),q(q) {}
};

vector<Device> d[maxn];

void init()
{
	for(int i=0;i<n;++i) d[i].clear();
	id.clear();
	type=0;
	maxq=0;
}


bool ok(int q)
{
	ll waste=0;
	for(int i=0;i<type;++i){
		int cheap=b+1;
		bool flag=false;
		for(int j=0;j<d[i].size();++j)
			if(d[i][j].q>=q) cheap=min(cheap,d[i][j].p);
		waste+=cheap;
		if(waste>b) return false;
	}
	return true;
}

int solve()
{
	int l=0,r=maxq;
	while(l<r){
		int m=l+(r-l+1)/2;
		if(ok(m)) l=m;
		else r=m-1;
		//cout<<l<<" "<<r<<endl;
	}
	return l;
}

int main()
{
	//freopen("test","r",stdin);
	int kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d %d",&n,&b);
		init();
		char s[30],name[30];
		int p,q; 
		for(int i=0;i<n;++i){
			scanf("%s %s %d %d",s,name,&p,&q);
			d[ID(s)].push_back(Device(p,q));
			maxq=max(q,maxq);
		}
		printf("%d\n",solve());
	}
	return 0;
}


