#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 1000010;
vector<int> pri;
vector<int> fac[maxn];
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
				fac[j].push_back(i);
			   	vis[j] = 1;
			}
		}
	}
}

double dp(int n)
{
	if(n==1) return 0;
	if(vis[n]) return d[n];
	vis[n] = 1;
	d[n] = 0;
	for(int i=0;i<fac[n].size();++i)	
	{
		d[n] += dp(n/fac[n][i]);
	}
	int sum = upper_bound(pri.begin(),pri.end(),n) - pri.begin() ;
	d[n] += sum;
	d[n] /= fac[n].size();
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
