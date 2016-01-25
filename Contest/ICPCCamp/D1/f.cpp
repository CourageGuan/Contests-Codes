#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
const LL mod = 1e9 + 7;
const int maxd = (1<<16) + 10;

LL dp[maxd];
int n,d;

vector<int> save[maxd],vec;

int main()
{
    //freopen("test.txt","r",stdin);
    scanf("%d %d",&n,&d);
    for(int i=0;i<n;++i)
    {
        char c[20];
        int cur = 0;
        scanf("%s",c);
        for(int i=0;i<d;++i)
        {
            cur <<= 1;
            cur += c[i] -'0';
        }
        vec.push_back(cur);
        if(!save[cur].size()) save[cur].push_back(cur);
    }
    for(int i=0;i<(1<<d);++i)
    {
        if(save[i].size())
        {
            for(int s = (i-1)&i ; s ;s = (s-1)&i)
            {
                if(save[s].size()) save[i].push_back(s);
            }
            if(i && save[0].size()) save[i].push_back(0);
        }
    }
    memset(dp,0,sizeof dp);
    LL ans = 0;
    for(int i=0;i<n;++i)
    {
        int p = vec[i];
        for(int j=0;j<save[p].size();++j)
        {
         //   printf("%d...%d %d\n",p,save[p][j],dp[save[p][j]]);
            dp[p] = (dp[p] + dp[save[p][j]]) %mod;
        }
        dp[p] = (dp[p] + 1)%mod;
       // printf("%lld\n",dp[p]);
    }
    for(int i=0;i<(1<<d);++i) ans = (ans + dp[i])%mod;
    printf("%lld\n",ans);
    return 0;
}

