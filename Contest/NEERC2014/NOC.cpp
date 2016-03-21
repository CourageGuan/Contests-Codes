#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define lowbit(x) ((x)&(-x))
int earn,debt;
int n;
const int maxn = 100000+10;
struct M
{
    int money,id;
    int time;
    M(int money = 0,int id = 0,int time = 0):money(money),id(id),time(time) {}
    bool operator < (const M& rhs) const {
        return time < rhs.time;
    }
};

M save[maxn];
int rk[maxn];

int CE[maxn];
int CC[maxn];

void add(int x,int v)
{
    if(v < 0)
    {
        for(int i = x;i <= n;i += lowbit(i))
        {
            if(CE[i] + v >= 0)
                CE[i] += v;
            else
            {
                CE[i] = 0;
                v += CE[i];
                CC[i] += v;
            }
        }
    }
    else
    {
        for(int i = x;i <= n; i+=lowbit(i))
            CE[i] += v;
    }

}

int rese,resc;

void query(int x)
{
    if(x - lowbit(x) > 0)
        query(x-lowbit(x));
    if(rese + CC[x] >= 0)
    {
        rese += CC[x];
        rese += CE[x];
    }
    else
    {
        int t = rese + CC[x];
        rese = 0;
        resc += t;




int main()
{
    scanf("%d",&n);
    int a,b,c,d,e;
    for(int i = 1;i <= n;++i)
    {
        scanf("%d %d.%d %d:%d",&a,&b,&c,&d,&e);
        save[i] = M(a,i,b*1e6+c*1e4+d*1e2+e);
    }
    sort(save,save+n);
    for(int i = 1;i <= n;++i)
        rk[save[i].id] = i;
    memset(CC,0,sizeof(CC));
    memset(CE,0,sizeof(CE));

