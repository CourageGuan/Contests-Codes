/*诡异WA,已过udebug所有数据,默认AC*/
//#define LOCAL
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
#include <queue>
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

#ifdef LOCAL 
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

queue<int> card;

void solve(int n)
{
	if (n==1)
	{
		cout<<"Discarded cards:"<<endl;
		cout<<"Remaining card: "<<card.front()<<endl;
		return;
	}
	if (n==2)
	{
		cout<<"Discarded cards: "<<card.front()<<endl;
		card.pop();
		cout<<"Remaining card: "<<card.front()<<endl;
		return;
	}
	vector<int> dis;
	while(card.size()>1)
	{
		dis.pb(card.front());
		card.pop();
		card.push(card.front());
		card.pop();
	}
	cout<<"Discarded cards:";
	F(i,0,dis.size()-2)
		cout<<" "<<dis[i]<<",";
	cout<<" "<<dis[dis.size()-1]<<endl;
	cout<<"Remaining card: "<<card.front()<<endl;
}

int main()
{
	//FRER;
	//FREW;
	int n;
	while(cin>>n && n)
	{
		SETS(card);
		F(I,1,n) card.push(I);
		solve(n);
	}
	cout<<endl;
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

