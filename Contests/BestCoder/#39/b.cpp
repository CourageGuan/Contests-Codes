#include<stdio.h>
#include<iostream>
#include<set>
#include<math.h>
#include<vector>
using namespace std;

const int maxn=10000;
set<int> has;
set<int> fac[maxn][(int)sqrt(maxn+0.5)];

int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}

inline void init()
{
	for(int i=2;i<=maxn;++i)
		for(int j=i+1;j<=maxn;++j){
			int t=gcd(i,j);
			if(t!=1){ 
				fac[i][t].insert(j);
				fac[j][t].insert(i);
			}
		}
}

int main()
{
	int n,x;
	init();
	while(~scanf("%d",&n)){
		has.clear();
		scanf("%d",&x);
		has.insert(x);
		int ans=0;
		for(int i=2;i<=n;++i){
			scanf("%d",&x);
			for(int j=0;j<fac[x].size();++j){
                //cout<<fac[x][j]<<" ";
				if(has.empty()) break;
				if(has.find(fac[x][j])!=has.end()){
				   	ans+=i;
					has.erase(fac[x][j]);
				}
			}
			has.insert(x);
			//puts("");

		}
		printf("%d\n",ans);
	}
	return 0;
}


