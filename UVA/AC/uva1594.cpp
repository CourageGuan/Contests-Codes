/*没好好读题，1000次以内算循环(数据200次即可)
  还有网上的方法不是按题意写的(没有判断1000次内的loop)，可是按题意写又TLE*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef map<string,int> MSI;
typedef map<int,int> MII;
typedef pair<int,int> PII;

#define F(i,a,b) for(int i=a;i<=b;i++)
#define Fd(i,a,b) for(int i=a;i>=b;i--)
#define SET(a,t) memset(a,t,sizeof(a))
#define SETS(ST) while(!ST.empty()) ST.pop();
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define mp maker_pair
#define fi first
#define se second

//#define FRE
#ifdef FRE
	#define FRER freopen("test","r",stdin)
	#define FREW freopen("1","w",stdout)
#else
	#define FRER 
	#define FREW 
#endif

//#define DEBUG
#ifdef DEBUG
	#define debug(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
	#define OK puts("OK")
	#define C(a) cout<<"~~"<<a<<"~~"<<endl
	#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;} 
#else
    #define debug(args...)              
	#define OK 
	#define C(a) 
	#define PM(a,x,y)  
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
	    cerr<<v<<" ";    
	    return *this;    
	}
} dbg;

const int mv4[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int mv8[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
const int inf = 0x7fffffff;
const int _inf= 0x8fffffff;
const LL  INF = 1e18;
const double EPS = 1e-8;
const double pi = acos(-1.0);

double ROUNDF(double x,int n){
	double t1,t2=modf(x,&t1);
	double t3=pow(10,n);
	long t4=long(t2*t3+0.5);
	x=t1+t4/t3;
	return x;
}

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}


/*-----  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux  -----*/
//set<LL> s;
map<LL,int> ss;

LL num(int a[],int n)
{
	LL ans=0;
	F(i,1,n)
		ans+=a[i]*pow(10,n-i);
	return ans;
}

int main()
{
	//FRER;
	//FREW;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a[20];
		int n,b[20];
		scanf("%d",&n);
		SET(a,0);
		SET(b,0);
		//s.clear();
		ss.clear();
		F(i,1,n)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		int _=0;
		while(_++<=200)
		{
			/*F(i,1,n) cout<<a[i]<<' ';
			cout<<endl;
			cout<<num(a,n)<<endl;*/
			if(num(a,n)==0)
			{
				printf("ZERO\n");
				break;
			}
			/*bool flag=1;
			int t=a[1];
			F(i,2,n)
				if(a[i]!=t){
					flag=0;
					break;
				}
			if(flag){
				printf("ZERO\n");
				break;
			}*/
			if(ss[num(a,n)])
			{
				printf("LOOP\n");
				break;
			}
			ss[num(a,n)]=1;
			F(i,1,n-1) a[i]=abs(b[i]-b[i+1]);
			a[n]=abs(b[n]-b[1]);
			F(i,1,n) b[i]=a[i];
		}
		if(_>200)
			printf("LOOP\n");
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

