#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int maxn=100000 +5;
bool bad[maxn];

void factor(int n,vector<int> &primes)
{
	for(int i=2;i<=(int)sqrt(n+0.5);++i)
		if(n % i==0){
			primes.push_back(i);
			while(n%i==0) n/=i;
		}
	if(n>1) primes.push_back(n);
}

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)==2){
		vector<int> primes;
		memset(bad,0,sizeof(bad));
		factor(m,primes);
		--n;
		for(int i=0;i<primes.size();++i){
			int p=primes[i];
			int min_e=0,e=0,x=m;
			while(x%p==0) { x/=p;++min_e; }
			for(int k=1;k<n;++k){
				x=n-k+1;
				while(x%p==0){ x/=p;++e; }
				x=k;
				while(x%p==0){ x/=p;--e; }
				if(e<min_e) bad[k]=1;
			}
		}
		vector<int> ans;
		for(int i=1;i<n;++i) if(!bad[i]) ans.push_back(i+1);
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i){
			if(i) printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
	}
	return 0;
}


