/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2014年12月31日 星期三 00时15分29秒
 & File Name: T3.cpp
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
#define ALL(x) x.begin(),x.end()
#define SET(a,t) memset(a,t,sizeof(a))
#define SETS(ST) while(!ST.empty()) ST.pop();
#define DEBUG puts("OK")
#define C(a) cout<<"~~"<<a<<"~~"<<endl
#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;} 

#define FRER freopen("test","r",stdin)
#define FREW freopen("1","w",stdout)

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


int main()
{
	//FRER;
	//FREW;
	int w[600],day[1200],n,m,ans=0;
	scanf("%d %d",&n,&m);
	SET(w,0);
	SET(day,0);
	F(i,1,n)
	   	scanf("%d",&w[i]);
	int _=1;
	F(i,1,m+1){
		int d;
	   	scanf("%d",&d);	
		if(d!=day[_]){
			day[_]=d;
			_++;
		}

	}
	_--;
	//F(i,1,_) C(day[i]);
	set<int> s;
	F(i,2,_){
		s.clear();
		Fd(j,i-1,1){
			if(day[j]==day[i]) break;
			if(!s.count(day[j])){
				ans+=w[day[j]];
				s.insert(day[j]);
			}
		}
	}
	/*F(i,1,_){
		ans+=(f[day[i]]-w[day[i]]);
		C(ans);
		f[day[i]]=w[day[i]];
	}*/
	printf("%d\n",ans);
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

