/*写了map还是TLE，～求分析哪里慢了...*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月06日 星期二 22时25分30秒
 & File Name: uva1597.cpp
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sstream>

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
#define md "----------"
#define mk "=========="
#define sorry "Sorry, I found nothing."

map<string,VI > msi[123];
vector<string> art[123];
int n,m;

void init()
{
	F(i,0,n){
		msi[i].clear();
		art[i].clear();
	}
}

void dic(string s,int i,int j) 	// ith article , jth line
{
	string::iterator it;
	for(it=s.begin();it!=s.end();++it)
		if(!isalpha(*it)) *it=' ';
			else *it=tolower(*it);
	stringstream ss(s);
	string word;
	while(ss>>word){
		if ((msi[i][word].size()>0 && msi[i][word].back()!=j) || msi[i][word].empty())
			msi[i][word].pb(j);
	}
}

void deal(string s)
{
	int pr=0;
	F(i,1,n){
		int flag=0;
		VI v=msi[i][s];
		if(!v.empty()){
			F(j,0,v.size()-1){
				flag++;
				if(flag==1){
					flag++;
					pr++;
				}
				if(pr && pr!=1) puts(md);
				cout<<art[i][v[j]-1]<<endl;
			}
		}
	}
	if (!pr) puts(sorry);
	puts(mk);
}

void dealo(string s1,string s2)
{
	int pr=0;
	F(i,1,n){
		int flag=0;
		VI v1=msi[i][s1],v2=msi[i][s2];
		if(!v1.empty() || !v2.empty()){
			int j1=0,j2=0;
			while(j1<v1.size() || j2<v2.size()){
				int j;
				if(j1==v1.size()) 
					j=v2[j2++];
				else if(j2==v2.size()) 
					j=v1[j1++];
				else
				{
					j=min(v1[j1],v2[j2]);
					if (v1[j1]<v2[j2]) j1++;
					else if(v1[j1]>v2[j2]) j2++;
					else{j1++;j2++;}
				}
				flag++;
				if(flag==1){
					flag++;
					pr++;
				}
				if(pr && pr!=1) puts(md);
				cout<<art[i][j-1]<<endl;
			}
			continue;
		}
	}
	if (!pr) puts(sorry);
	puts(mk);
}

void deala(string s1,string s2)
{
	int pr=0;
	F(i,1,n){
		int flag=0;
		VI v1=msi[i][s1],v2=msi[i][s2];
		if(!v1.empty() && !v2.empty()){
			int j1=0,j2=0,j;
			while(j1!=v1.size() || j2!=v2.size()){
				if(j1==v1.size()) j=v2[j2++];
				else if(j2==v2.size()) j=v1[j1++];
				else{
					j=min(v1[j1],v2[j2]);
					if (v1[j1]<v2[j2]) j1++;
					else if(v1[j1]>v2[j2]) j2++;
					else{j1++;j2++;}
				}
				flag++;
				if(flag==1){
					flag++;
					pr++;
				}
				if(pr && pr!=1) puts(md);
				cout<<art[i][j-1]<<endl;
			}
			continue;
		}
	}
	if(!pr) puts(sorry);
	puts(mk);
}

void dealn(string s)
{
	int pr=0;
	F(i,1,n){
		int f=0;
		VI v=msi[i][s];
		if(!v.empty()) continue;
		F(j,0,art[i].size()-1){
			f++;
			if(f==1){
				f++;
				pr++;
			}
			if(pr && pr!=1 && f==2) puts(md);
			cout<<art[i][j]<<endl;
		}
	}
	if(!pr) puts(sorry);
	puts(mk);
}

void solve()
{
	scanf("%d",&n);
	getchar();
	int i=1,j=1;
	while(i<=n)
	{
		string s;
		getline(cin,s);
		if(s[0]=='*'){
			i++;
			j=1;
			continue;
		}
		art[i].pb(s);
		dic(s,i,j++);
	}
	scanf("%d",&m);
	getchar();
	while(m--)
	{
		string s;
		getline(cin,s);
		if(s.find("AND")!=-1){
			string s1=s.substr(0,s.find('A')-1),
				   s2=s.substr(s.find('D')+2,s.size()-s.find('D')-2);
			deala(s1,s2);
			continue;
		}
		if(s.find("OR")!=-1){
			string s1=s.substr(0,s.find('O')-1),
				   s2=s.substr(s.find('R')+2,s.size()-s.find('R')-2);
			dealo(s1,s2);
			continue;
		}
		if(s.find("NOT")!=-1){
			s.erase(0,4);
			dealn(s);
			continue;
		}
		deal(s);
	}
}

int main()
{
	FRER;
	//FREW;
	init();
	solve();
	printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}



