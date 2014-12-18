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
#define FREW freopen("815.out","w",stdout)


const double PI=acos(-1.0);
const int MAXN=0x7fffffff;
const int MINN=0x8fffffff;
const int EPS=1e-7;
const int N=35;

/*
   on ne voit bien qu'avec le coeur.l'essentiel est invisible pour les yeux
                                                                            */
int m,n;

void  solve(int m,int n)
{
  int avg=0,ans=0;
  int reg[N*N];
  int sum=n*m;
  SET(reg,0);
  F(i,1,sum)
  {
    int d;
    scanf("%d",&d);
    reg[i]=d;
  }
  sort(reg+1,reg+sum+1);
  //F(i,1,sum) cout<<reg[i]<<" ";
  int v;
  scanf("%d",&v);
  double avgd;
  F(i,1,sum)
  {
    if((avg+(reg[i+1]-reg[i])*i)*100<v && i<sum)
      avg+=(reg[i+1]-reg[i])*i;
	else
	{
	  ans=i;
	  //C(ans);
	  avgd=reg[i]+double(v-100*avg)/double(i*100);
	  break;
	}
  }
  //PM(reg,m+1,n+1);
  //DEBUG;
  //C(avgd);
  printf("Water level is %.2f meters.\n",avgd);
  printf("%.2f percent of the region is under water.\n\n",double(ans*100)/double(sum));
}

int main()
{
  //FRER;
  //FREW;
  int _=0;
  while(scanf("%d%d",&m,&n)==2&m&n){
    _++;
    printf("Region %d\n",_);
    solve(m,n);
  }
  return 0;
}
