/*题目很水，思路很乱，累*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月06日 星期二 11时33分28秒
 & File Name: uva230.cpp
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
#define max(a,b) (a>b)?(a):(b)
#define min(a,b) (a<b)?(a):(b)
#define F(i,a,b) for(int i=(a);i<=(b);(i)++)
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
struct book{
	string name,author;
	bool operator<(const book s)const{
		if(author==s.author) return name<s.name;
		else return author<s.author;
	}
};

vector<int> vi;
vector<book> vb;
priority_queue<int,vector<int>,greater<int> > ret;
MSI msi;
int n;

void deal(char c,string s)
{
	if(c=='B')
		vi[msi[s]]=-1;
	else
		ret.push(msi[s]);
}

void solve()
{
	while(!ret.empty())	
	{
		int n=ret.top(),m;
		ret.pop();
		bool flag=false;
		Fd(j,n-1,0)
			if (vi[j]!=-1) 
			{
				flag=true;
				m=j;
				break;		
			}
		vi[n]=n;
		if(flag)
			cout<<"Put \""<<vb[n].name<<"\" after \""<<vb[m].name<<"\""<<endl;	
		else
			cout<<"Put \""<<vb[n].name<<"\" first"<<endl;	
	}
	puts("END");
}

int main()
{
	FRER;
	FREW;
	string s;
	msi.clear();vi.clear();
	vb.clear();SETS(ret);
	while(getline(cin,s) && s[0]!='E')
	{
		s.erase(0,1);
		string name=s.substr(0,s.find('"')),author=s.substr(s.find("by"),s.size()-s.find("by"));
		book b;
		b.name=name;b.author=author;
		vb.pb(b);
	}
	sort(ALL(vb));
	vector<book>::iterator it;
	for(it=vb.begin();it!=vb.end();++it)
		debug(it->name,it->author);
	F(i,0,vb.size()-1){
		msi[vb[i].name]=i;
		vi.pb(i);
	}
	while(getline(cin,s) && s[0]!='E')
	{
		if (s.find('"')!=-1)
		{
			string ss=s.substr(s.find('"')+1,s.size()-s.find('"')-2);
			deal(s[0],ss);
		}
		else solve();
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}



