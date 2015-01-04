/*这个模拟太恶心了,不想debug了..*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2015年01月04日 星期日 18时28分43秒
 & File Name: uva1596.cpp
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

#define F(i,a,b) for(int i=a;i<=b;i++)
#define Fd(i,a,b) for(int i=a;i>=b;i--)
#define SET(a,t) memset(a,t,sizeof(a))
#define SETS(ST) while(!ST.empty()) ST.pop();
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define DEBUG
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

#define FRE
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


MSI arr,now;

void init()
{
	arr.clear();
	now.clear();
}

int stoi(string s)
{
	int n,len=s.size();
	Fd(i,0,len-1)
	{
		n+=s[i]-48;
		n*=10;
	}
	return n/10;
}

string itos(int n)
{
	char s[20];
	int len=(int)log10(n)+1;
	Fd(i,len-1,0)
	{
		s[i]=(char)(n%10+48);
		n/=10;
	}
	string ss=s;
	return ss;
}


bool isb1(string ss,bool flag,int& number)
{
	string s=ss;
	int len=s.size();
	string name0,sn[100];
	int pos=s.find("[");
	name0=s.substr(0,pos);
	sn[0]=name0;
	s.erase(0,pos+1);
	int n=0;
	while(!isdigit(s[0])){
		int pos=s.find("[");
		string name=s.substr(0,pos);
		if(!arr[name]) return false;
		s.erase(0,pos+1);
		sn[++n]=name;
	}
	int num=stoi(sn[n]);
	Fd(i,n,1){
		if(num>=arr[sn[i]]) return false;
		string sss=s[n]+"["+itos(num)+"]";
		if(!now[sss]) return false;
		num=(now[sss]==-1)?0:now[sss];
	}
	if (flag) arr[name0]=num;
	else number=num;
	return true;
}

bool isbug(string ss)
{
	string s=ss;
	int len=s.size(),nn;
	if(s.find('=')==-1)
		return isb1(s,1,nn);
	else
	{
		int pos=s.find('=');
		string s1=s.substr(0,pos),s2=s.substr(pos+1,len-pos);
		if(s2.find("[")!=-1){
			int pos1=s1.find('['),pos2=s2.find('[');
			int n1,n2;
			string name1=s1.substr(0,pos),name2=s2.substr(0,pos);
			if(!arr[name1] || !arr[name2]) return false;
			if(!isb1(s1,0,n1) || !isb1(s2,0,n2)) return false;
			string ss=name1+"["+itos(n1)+"]",sss=name2+"["+itos(n2)+"]";
			now[ss]=now[sss];
		}
		else
		{
			int pos1=s1.find('[');
			int n1;
			string name1=s1.substr(0,pos);
			if(!arr[name1]) return false;
			if(!isb1(s1,0,n1)) return false;
			string ss=name1+"["+itos(n1)+"]";
			int n2=(stoi(s2)==0)?-1:stoi(s2);
			now[ss]=n2;
		}
	}
	return true;
}

int main()
{
	FRER;
	//FREW;
	string s;
	int kase=1,bug=1;
	bool flag=true;
	while(cin>>s)
	{
		int k=kase;
		if(s==".") kase++;
		if(k!=kase){
			init();
			bug=1;
			if(flag) cout<<0<<endl;
			flag=true;
		   	continue;
		}
		if(!flag) continue;
		if(isbug(s)){
			cout<<bug<<endl;
			flag=false;
		}
		bug++;
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}


