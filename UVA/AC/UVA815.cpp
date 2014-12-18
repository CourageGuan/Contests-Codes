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

#define FRER freopen("test","r",stdin)
#define FREW freopen("1","w",stdout)


const double PI=acos(-1.0);
const int MAXN=0x7fffffff;
const int MINN=0x8fffffff;
const double EPS=1e-7;
const int N=35;

/*
   on ne voit bien qu'avec le coeur.l'essentiel est invisible pour les yeux
                                                                            */

void  solve(int m,int n)
{
  //DEBUG;
  double avg=0.0,ans=0.0;
  double reg[N*N];
  int sum=n*m;
  SET(reg,0.0);
  F(i,1,sum)
    scanf("%lf",&reg[i]);
  sort(reg+1,reg+sum+1);
  double v;
  scanf("%lf",&v);
  v/=100.0;
  //C(v);
  //F(i,1,sum) cout<<reg[i]<<" ";
  F(i,1,sum)
    if((avg+(reg[i+1]-reg[i])*i)<=v && i<sum)
      avg+=(reg[i+1]-reg[i])*i;
	  else{
	    //if(abs(v-avg)<EPS) ans=(i-1)*1.0/sum;
      ans=i*1.0/sum;
	    //C(ans);
	    avg=reg[i]+(v-avg)/i;
	    break;
    }
  //PM(reg,m+1,n+1);
  //DEBUG;
  //C(avgd);
  printf("Water level is %.2lf meters.\n",avg);
  printf("%.2lf percent of the region is under water.\n",ans*100);
}

int main()
{
  //FRER;
  //FREW;
  int m,n,_=1;
  while(scanf("%d%d",&m,&n)==2&&m&&n)
  {
    printf("Region %d\n",_++);
    solve(m,n);
    printf("\n");
  }
  return 0;
}
