#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL COUNTS = 1e9;

int n,k;
double x,y;
struct P{
    int x,y,z;
    P() {}
    P(int x,int y,int z):x(x),y(y),z(z) {}
    double dis(const double& xx,const double& yy) const{
        return sqrt((x-xx)*(x-xx) + (y-yy)*(y-yy));
    }
} p[110];

bool cmp(const P& a,const P& b)
{
    return a.dis(x,y) < b.dis(x,y);
}

LL cnt[11];
pair<double,int> tmp[110];

inline void gao()
{
    for(int i=0;i<n;++i) tmp[i].first = p[i].dis(x,y),tmp[i].second = i;
    sort(tmp,tmp+n);
    cnt[p[tmp[k-1].second].z]++;
}

inline double getP()
{
    return (double)rand()/RAND_MAX*10000;
}

int main()
{
    freopen("dogfood_input.txt","r",stdin);
    //freopen("test.txt","r",stdin);
    srand(time(0));
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);

    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if(p[i].x == p[j].x && p[i].y == p[j].y)
                puts("cd");
    return 0;
    for(register LL i=0;i<COUNTS;++i)
    {
        if(i % int(1e7) == 0) printf("%lld\n",i);
        y = getP();
        x = getP();
 //     cout << x <<" "<< y << endl;
        gao();
    }
    for(int i=1;i<=10;++i)
    {
        printf("%.10lf\n",(double)cnt[i]/COUNTS);
    }
    return 0;
}
