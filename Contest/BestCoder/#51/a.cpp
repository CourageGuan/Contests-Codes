//经典TSP问题改编
//每座城市可以经过多次
//先floyd松弛，然后d[i][S]表示从i出发当前状态为S的最短距离
//和TSP不一样的是当前状态有i时也要更新状态。
//最后答案为d[0][(1<<n)-1]
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long LL;
const int maxn = 20;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn];
int d[maxn][1<<maxn];
int n,m;


int main()
{
    //freopen("test.txt","r",stdin);
    int T;        
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        memset(G,0,sizeof G);
        for(int i=0;i<m;++i)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            if(u==v) continue;
            if(G[u-1][v-1])
                G[u-1][v-1] = G[v-1][u-1] = min(G[u-1][v-1],w);
            else
                G[u-1][v-1] = G[v-1][u-1] = w;
        }
        if(n==1)
        {
               puts("0");
            continue;
        }
        int ans = 0;
        for(int i=1;i<n;++i) ans += 2*G[i][0];
        for(int i=1;i<n;++i)
            for(int j=i+1;j<n;++j)
                ans -= G[i][j];

        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    if(G[i][k] && G[k][j])
                    {
                        if(!G[i][j]) G[i][j] = G[i][k] + G[k][j];
                        else G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
                    }

        memset(d,INF,sizeof d);
        d[0][0] = 0  ;
        for(int j=0;j<(1<<n);++j)
        {
            for(int i=0;i<n;++i)
            {
                if(d[i][j]<INF)
                {
                    for(int t=0;t<n;++t)
                    {
                        if(j&(1<<t) || !G[t][i]) continue;
                        d[t][j|(1<<t)] = min(d[t][j|(1<<t)],d[i][j] + G[t][i]);
                    }
                }
            }
        }    
        ans = d[0][(1<<n)-1];
        printf("%d\n",ans);
    }
    return 0;
}

