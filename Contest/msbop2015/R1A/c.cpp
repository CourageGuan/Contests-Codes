#include<bits/stdc++.h>
using namespace std;

const int maxn=500010;
bool vist[maxn];
int id[maxn];
vector<int> primes;
int fa[1005];
int save[1005];
int n;

bool vis[1005];
vector<int> G[1005];
int match[1005];

void init()
{
	primes.clear();
	memset(vist,0,sizeof(vist));
	primes.push_back(2);
	for(int i=3;i<maxn;i+=2) if(!vist[i]){
		primes.push_back(i);
		for(int j=i;j<maxn;j+=i) vist[j]=1;
    }
}

bool dfs(int u)
{
    for(int i = 0; i < G[u].size();++i)
    {
        int v = G[u][i];
        if(!vis[v])
        {
            vis[v] = 1;
            int t = match[v]; match[v] = u;
            if(t == -1 || dfs(t)) return true;
            match[v] = t;
        }
    }
    return false;
}

int solve()
{
    int ans = 0;
    memset(match,-1,sizeof(match));
    for(int i = 1;i <= n;++i)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    return ans;
}



int main()
{
	//freopen("test.txt","r",stdin);
	init();
	int T,kase=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(id,0,sizeof(id));
		for(int i=1;i<=n;++i){
		   	scanf("%d",save+i);
			id[save[i]]=i;
		}
		int t=0;
		for(int i=0;i<1005;++i) G[i].clear();
		for(int i=1;i<=n;++i){
			for(int j=0;j<primes.size();++j){
				if(save[i]*primes[j]>=maxn) break;
				if(id[save[i]*primes[j]]){
					G[id[save[i]*primes[j]]].push_back(i);
					G[i].push_back(id[save[i]*primes[j]]);
				}
			}
		}
		printf("Case #%d: %d\n",++kase,n-(solve())/2);
	}
	return 0;
}

