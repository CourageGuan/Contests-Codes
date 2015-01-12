/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2014年12月27日 星期六 20时41分01秒
 & File Name: uva400
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

string s[105];
int n;

void init()
{
	F(i,0,n-1) s[i].clear();
}



void print(int n,char ch)
{
	F(i,1,n) printf("%c",ch);
	cout<<endl;
}

void solve(int mmax,int n)
{
	int col=(60-mmax)/(mmax+2)+1,row=n%col?n/col+1:n/col,more=n%row,len=mmax;
	//C(col);C(row);C(more);C(len);
	sort(s,s+n);
	int ss[105][60];
	SET(ss,0);
	if(col==1)
	{
		F(i,0,n-1){
			s[i].resize(len,' ');
			cout<<s[i]<<endl;
		}
		return;
	}
	int t=0;
	F(i,1,col)
		F(j,1,row){
			if(i==col)
				s[t].resize(len,' ');
			else
				s[t].resize(len+2,' ');
			ss[j][i]=t++;
		}
	F(i,1,row)
	{
		F(j,1,col) if(ss[i][j]<n) cout<<s[ss[i][j]];
		cout<<endl;
	}
}

int main()
{
	//FRER;
	//FREW;
	while(scanf("%d",&n)==1)
	{
		print(60,'-');
		int mmax=0;
		//init();
		F(i,0,n-1)
		{
			cin>>s[i];
			//cout<<s[i]<<endl;
			if (s[i].size()>mmax) mmax=s[i].size();
		}
		solve(mmax,n);
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}






