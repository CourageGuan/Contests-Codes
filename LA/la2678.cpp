//二分查找 0.036s
//根据递增序列的性质的O(n)算法	0.029s ...
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<int> p;

/*
int main()
{
	//freopen("test","r",stdin);
	int n,s;
	while(scanf("%d %d",&n,&s)==2){
		p.clear();
		int a,ans=n+1,cur=0;
		p.push_back(0);
		for(int i=1;i<=n;++i){
			scanf("%d",&a);
			cur+=a;
			p.push_back(cur);
			int pos=lower_bound(p.begin(),p.end(),cur-s)-p.begin();
			if(pos>0) ans=min(ans,i-pos+1);
		}
		printf("%d\n",ans%(n+1));
	}
	return 0;
}*/

int main()
{
	//freopen("test","r",stdin);
	int n,s;
	while(scanf("%d %d",&n,&s)==2){
		p.clear();
		int a,ans=n+1,cur=0,pos=1;
		p.push_back(0);
		for(int i=1;i<=n;++i){
			scanf("%d",&a);
			cur+=a;
			p.push_back(cur);
			if(p[pos-1]>cur-s) continue;
			while(p[pos]<=cur-s) ++pos;
			ans=min(ans,i-pos+1);
		}
		printf("%d\n",ans%(n+1));
	}
	return 0;
}
