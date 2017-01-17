#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+100;

struct Edge
{
    int v,w;
    int nxt;
    Edge(int v = 0,int w = 0):v(v),w(w) {nxt = -1;}
};

Edge save[2*maxn];
int cur;
int head[2*maxn];

void addEdge(int from,int to,int w)
{
    save[cur] = Edge(to,w);
    save[cur].nxt = head[from];
    head[from] = cur++;
}

typedef long long LL;
const LL INF = 0x3f3f3f3f;
LL dp[maxn][2];
LL costfa[maxn];
LL A[maxn];
int n;

inline void init()
{
    cur = 0;
    for(int i = 0;i <= 2*n;++i)
        head[i] = -1;
}

void dfs1(int u,int fa)
{
    bool isleaf = true;
    LL sumback = 0;
    LL Maxunback = -INF;
    for(int i = head[u];i != -1; i = save[i].nxt)
    {
        int v = save[i].v;

        LL w = save[i].w;

        if(v != fa)
        {
            isleaf = false;
            costfa[v] = w;
            dfs1(v,u);
            LL t = dp[v][1] - 2*w;
            if(t >= 0)
            {
                sumback += t;
                Maxunback = max(Maxunback,-t + dp[v][0]-w);
            }
            else
            {
                Maxunback = max(Maxunback,dp[v][0]-w);
            }
        }
    }

    sumback += A[u];
    if(isleaf)
    {
        dp[u][0] = dp[u][1] = A[u];
    }
    else
    {
        dp[u][1] = sumback;
        dp[u][0] = max(dp[u][1],dp[u][1]+Maxunback);
    }
}

LL res[maxn][2];

void dfs2(int u,int fa,LL faback,LL faunback)
{
    LL sumback = 0;
    LL Max = -INF;
    LL Max2 = -INF;

    LL t = faback-2*costfa[u];
    if(t >= 0)
    {
        sumback += t;
        LL now = -t + faunback - costfa[u];
        if(Max <= now)
        {
            Max2 = Max;
            Max = now;
        }
        else if(Max2 <= now)
        {
            Max2 = now;
        }
    }
    else
    {
        LL now = faunback-costfa[u];
        if(Max <= now)
        {
            Max2 = Max;
            Max = now;
        }
        else if(Max2 <= now)
        {
            Max2 = now;
        }
    }

    for(int i = head[u];i != -1; i = save[i].nxt)
    {
        int v = save[i].v;

        LL w = save[i].w;

        if(v != fa)
        {
            LL t = dp[v][1] - 2*w;
            if(t >= 0)
            {
                sumback += t;

                LL now = -t + dp[v][0]-w;
                if(Max <= now)
                {
                    Max2 = Max;
                    Max = now;
                }
                else if(Max2 <= now)
                {
                    Max2 = now;
                }
            }
            else
            {
                LL now = dp[v][0]-w;
                if(Max <= now)
                {
                    Max2 = Max;
                    Max = now;
                }
                else if(Max2 <= now)
                {
                    Max2 = now;
                }
            }
        }
    }

    sumback += A[u];

    res[u][1] = sumback;
    res[u][0] = max( res[u][1],res[u][1] + Max);

    for(int i = head[u];i != -1; i = save[i].nxt)
    {
        int v = save[i].v;

        LL w = save[i].w;
        if(v != fa)
        {
            LL t = dp[v][1] - 2*w;
            if(t >= 0)
            {
                LL now = -t + dp[v][0]-w;
                LL need;
                if(now == Max)
                    need = Max2;
                else
                    need = Max;
                LL nxtfaback = sumback - t;
                LL nxtfaunback = sumback - t + need;

                dfs2(v,u,nxtfaback,nxtfaunback);
            }
            else
            {
                LL now = dp[v][0]-w;
                LL need;
                if(now == Max)
                    need = Max2;
                else
                    need = Max;
                LL nxtfaback = sumback;
                LL nxtfaunback = sumback + need;
                dfs2(v,u,nxtfaback,nxtfaunback);
            }
        }
    }
}

int main()
{
 //  freopen("./test.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    for(int z = 1;z <= kase;++z)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;++i)
        {
            scanf("%d",&A[i]);
        }
        init();
        for(int i = 0;i < n-1;++i)
        {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            addEdge(a,b,w);
            addEdge(b,a,w);
        }

        dfs1(1,0);
        res[0][0] = res[0][1] = 0;
        costfa[1] = 0;
        dfs2(1,0,0,0);

        printf("Case #%d:\n",z);
        for(int i = 1;i <= n;++i)
            printf("%d\n",max(res[i][0],res[i][1]));
    }
    return 0;
}
