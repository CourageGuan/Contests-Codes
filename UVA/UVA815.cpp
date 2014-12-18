#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
//#include<ctime>

#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>

using namespace std;
//ios::sync_with_stdio(false);  //speed

typedef vector<int> VI;
typedef map<string,int> MSI;
typedef map<int,int> MII;
typedef pair<int,int> PII;
typedef long long LL;
typedef double DB;


#define F(i,a,b) for(int i=a;i<=b;i++)
#define Fd(i,a,b) for(int i=a;i>=b;i--)
#define C(a) cout<<a<<endl 
#define SET(a,t) memset(a,t,sizeof(a))
#define SETS(ST) while(!ST.empty()) ST.pop();
#define DEBUG puts("!BUG!")
#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;} //Print Matrix

#define FRER freopen("815.in","r",stdin)
#define FREW freopen(".out","w",stdout)


const double PI=acos(-1.0);
const int MAXN=0x7fffffff;
const int MINN=0x8fffffff;
const int EPS=1e-7;
const int N=50;

/*
   on ne voit bien qu'avec le coeur.l'essentiel est invisible pour les yeux
                                                                            */
int m,n;

void  solve(int m,int n)
{
  int avg=0;
  int reg[N][N];
  SET(reg,0);
  F(i,1,m)
    F(j,1,n)
    {
      int d;
      scanf("%d",&d);
      reg[i][j]=d;
      d*=100;
      avg+=d;
    }
  PM(reg,m+1,n+1);
  //DEBUG;
  int v;
  scanf("%d",&v);
  int sum=n*m;
  double avgd;
  avgd=(double(avg+v)/double(sum*100));
  C(avgd);
  printf("Water level is %.2f meters.\n",avgd);
  double ans=0;
  F(i,1,m)
    F(j,1,n)
      if (reg[i][j]<avg) ans++;
  printf("%.2f percent of the region is under water.\n",ans*100/sum);
}

int main()
{
  FRER;
  int _=0;
  while(scanf("%d%d",&m,&n)==2&m&n){
    _++;
    printf("Region %d\n",_);
    solve(m,n);
  }
  return 0;
}
