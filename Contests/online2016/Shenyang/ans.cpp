#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 10;
bool vis[maxn];
int primes[maxn];
int ans[maxn];
int tot=0;

void init()
{
	ans[1] = 0;
	for(int i=2;i<maxn;++i){
		ans[i] = ans[i-1];
		if(!vis[i])
		{
			++ans[i];
		   	primes[tot++]=i;
		}
		for(int j=0;j<tot;++j){
			int t=i*primes[j];
			if(t>maxn) break;
			vis[t]=1;
			if(i%primes[j]==0) break;
		}
	}
}

int main()
{
	init();
	freopen("ans.txt","w",stdout);
	int n;
	for(n=1;n<=10000;++n)
	{
		printf("%d %lld\n",n,ans[n]);
	}
	return 0;
}
