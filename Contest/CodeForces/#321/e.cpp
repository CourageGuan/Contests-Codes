#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100100 
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
typedef long long ull;

const ull base[2] = {11,13};
const ull mod[2] = {1e9+7,1073676287};

int n,m,k;
char s[N];
ull pow[2][N],sum[2][N];
ull hash[2][N<<2];
int col[2][N<<2];

void init()
{
	for(int d = 0;d<2;++d)
	{
		pow[d][0]=sum[d][0]=1;
		for(int i=1;i<=n;i++)
		{
			pow[d][i]=pow[d][i-1]*base[d]%mod[d];
			sum[d][i]=(sum[d][i-1]+pow[d][i])%mod[d];
		}
	}
    memset(col,-1,sizeof(col));
}
void pushup(int rt,int l,int r,int d)
{
    int mid=(l+r)>>1;
    hash[d][rt]=(hash[d][rt<<1]+hash[d][rt<<1|1]*pow[d][mid - l + 1])%mod[d];
}
void pushdown(int rt,int l,int r,int d)
{
    if(col[d][rt]!=-1)
    {
        int mid=(l+r)>>1;
        col[d][rt<<1]=col[d][rt];
        hash[d][rt<<1]=col[d][rt]*sum[d][mid-l]%mod[d];
        col[d][rt<<1|1]=col[d][rt];
        hash[d][rt<<1|1]=col[d][rt]*sum[d][r-mid-1]%mod[d];
        col[d][rt]=-1;
    }
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        hash[0][rt] = hash[1][rt] =s[l]-'0';
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt,l,r,0);
    pushup(rt,l,r,1);
}
void update(int v,int L,int R,int l,int r,int rt,int d)
{
    if(L<=l&&r<=R)
    {
        col[d][rt]=v;
        hash[d][rt]=v*sum[d][r-l]%mod[d];
        return;
    }
    int mid=(l+r)>>1;
    pushdown(rt,l,r,d);
    if(L<=mid)update(v,L,R,lson,d);
    if(R>mid)update(v,L,R,rson,d);
    pushup(rt,l,r,d);
}
ull query(int L,int R,int l,int r,int rt,int d)
{
    ull ret=0;
    if(L<=l&&r<=R)
    {
        return hash[d][rt];
    }
    int mid=(l+r)>>1;
    pushdown(rt,l,r,d);
    if(L>mid)ret=query(L,R,rson,d);
    else if(R<=mid)ret=query(L,R,lson,d);
    else ret=(query(L,mid,lson,d)+query(mid+1,R,rson,d)*pow[d][mid-L+1]%mod[d])%mod[d];
    return ret;
}
int main()
{
//	freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s",s+1);
    init();
    build(1,n,1);
    for(int i=1;i<=m+k;i++)
    {
        int opt,l,r,g;
        scanf("%d%d%d%d",&opt,&l,&r,&g);
        if(opt==1)
        {
			for(int d=0;d<2;++d)
            	update(g,l,r,1,n,1,d);
        }else
        {
			bool flag = true;
            if(g>r-l+1){puts("NO");continue;}
            if(g==r-l+1){puts("YES");continue;}
			for(int d=0;d<2;++d)
			{
				ull tmp1=query(l+g,r,1,n,1,d);
				ull tmp2=query(l,r-g,1,n,1,d);
				if(tmp1 != tmp2) 
				{
					flag = false;
					break;
				}
			}
			puts(flag?"YES":"NO");
        }
    }
}
