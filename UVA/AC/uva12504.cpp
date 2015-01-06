/*水题，纯模拟，最近几道题算法效率不高，算法优化需要系统提升*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月06日 星期二 17时33分13秒
 & File Name: uva12504.cpp
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
#include <queue>
#include <set>
#include <map>
#include <string>
#include <utility>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef map<string,int> MSI;
typedef map<int,int> MII;
typedef pair<int,int> PII;

#define LEN(n) (int)log10(n)+1
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
#define F(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Fd(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define SET(a,t) memset((a),(t),sizeof(a))
#define SETS(ST) while(!ST.empty()) ST.pop();
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

//#define DEBUG
#ifdef DEBUG
	#define debug(args...) do{cerr<<#args<<":"; dbg,args; cerr<<endl;}while(0) 
	#define OK puts("OK")
	#define C(a) cout<<"~~"<<a<<"~~"<<endl
	#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;} 
struct debugger{
	template<typename T> debugger& operator , (const T& v){
		cerr<<v<<" ";
		return *this;
	}
} dbg;
#else
	#define debug(args...)
	#define OK
	#define C(a)
	#define PM(a,x,y)
#endif

//#define FRE
#ifdef FRE
	#define FRER freopen("test","r",stdin)
	#define FREW freopen("1","w",stdout)
#else
	#define FRER
	#define FREW
#endif

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


MSI msi;
set<pair<string,string> > vs1,vs2;
set<string> ss1,ss2;

void init()
{
	msi.clear();
	vs1.clear();
	vs2.clear();
	ss1.clear();
	ss2.clear();
}

void solve()
{
	int _inc=0,_dec=0,_cha=0; 
	string inc[200],dec[200],cha[200];
	set<pair<string,string> >::iterator it1,it2;
	set<string>::iterator it;
	for(it=ss2.begin();it!=ss2.end();++it)
		if(!ss1.count(*it)) inc[_inc++]=*it;	
	for(it=ss1.begin();it!=ss1.end();++it)
		if(!ss2.count(*it)) dec[_dec++]=*it;	
	for(it1=vs1.begin();it1!=vs1.end();it1++)
		for(it2=vs2.begin();it2!=vs2.end();it2++)
			if(it1->fi==it2->fi && it1->se!=it2->se)
				cha[_cha++]=it1->fi;
	if(!_inc && !_dec && !_cha){
		cout<<"No changes\n\n";
		return;
	}
	if(_inc){
		cout<<"+";
		F(i,0,_inc-1){
			cout<<inc[i];
			if(i!=_inc-1) cout<<",";
		}
		cout<<endl;
	}
	if(_dec){
		cout<<"-";
		F(i,0,_dec-1){
			cout<<dec[i];
			if(i!=_dec-1) cout<<",";
		}
		cout<<endl;
	}
	if(_cha){
		cout<<"*";
		F(i,0,_cha-1){
			cout<<cha[i];
			if(i!=_cha-1) cout<<",";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	FRER;
	FREW;
	int t;
	cin>>t;
	getchar();
	while(t--){
		init();
		string s1,s2;
		getline(cin,s1);
		s1.erase(0,1);
		while(!s1.empty())
		{
			if(s1=="}") break;
			int pos=s1.find(':');
			string sk=s1.substr(0,pos);
			s1.erase(0,pos+1);
			pos=(s1.find(',')==-1)?s1.find('}'):s1.find(',');
			string sv=s1.substr(0,pos);
			s1.erase(0,pos+1);
			pair<string,string> p=mp(sk,sv);
			vs1.insert(p);
			ss1.insert(sk);
		}
		//sort(ALL(vs1))	
		getline(cin,s2);
		s2.erase(0,1);
		while(!s2.empty())
		{
			if(s2=="}") break;
			int pos=s2.find(':');
			string sk=s2.substr(0,pos);
			s2.erase(0,pos+1);
			pos=(s2.find(',')==-1)?s2.find('}'):s2.find(',');
			string sv=s2.substr(0,pos);
			s2.erase(0,pos+1);
			pair<string,string> p=mp(sk,sv);
			vs2.insert(p);
			ss2.insert(sk);
		}
		//sort(ALL(vs2));
		solve();
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}


