#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 1000010;
vector<int> pri;
bool vis[maxn];
double d[maxn];

void init()
{
	memset(vis,0,sizeof vis);
	for(int i=2;i<maxn;++i)
	{
		if(!vis[i])	
		{
			pri.push_back(i);
			for(int j=i;j<maxn;j+=i)
			{
			   	vis[j] = 1;
			}
		}
	}
	int cur = 1;
}

double dp(int n)
{
	if(n==1) return 0;
	if(vis[n]) return d[n];
	vis[n] = 1;
	int sum = 0 , p = 0; 
	for(int i=0;i<pri.size() && pri[i] <= n;++i)
	{
		++sum;
		if(n%pri[i] == 0)
		{
			++p;
		   	d[n] += dp(n/pri[i]); 
		}
	}
	d[n] = (d[n]+sum)/p;
	return d[n];
}

int main()
{
	//freopen("test.txt","r",stdin);
	init();	
	memset(vis,0,sizeof vis);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		int n;
		scanf("%d",&n);
		printf("Case %d: %.9f\n",z,dp(n));
	}
	return 0;
}

