/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2014年12月20日 星期六 10时20分26秒
 & File Name: uva156.cpp
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef map<string,int> MSI;
typedef map<int,int> MII;
typedef pair<int,int> PII;

#define F(i,a,b) for(int i=a;i<=b;i++)
#define Fd(i,a,b) for(int i=a;i>=b;i--)
#define C(a) cout<<a<<endl
#define SET(a,t) memset(a,t,sizeof(a))
#define SETS(ST) while(!ST.empty()) ST.pop();
#define DEBUG puts("OK")
#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;}

#define FRER freopen("test","r",stdin)
#define FREW freopen("1","w",stdout)

template <typename T>
bool cmp(T a,T b){return a>b;}

const int inf = 0x7fffffff;
const int _inf= 0x8fffffff;
const LL  INF = 1e18;
const double EPS = 1e-8;
const double pi = acos(-1.0);
const int N=1010  ;//The Range of Description

/*
  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux
                                                                          */

MSI M;
vector<string> v;

string ss(string s)
{
	string ch=s;
    transform(ch.begin(),ch.end(),ch.begin(),::tolower);
    sort(ch.begin(),ch.end());
	return ch;
}
void solve(string ch)
{
	if(!M.count(ss(ch))) M[ss(ch)]=0;
	M[ss(ch)]++;
}

int main()
{
	//FRER;
	string ch;
	int _=0;
	while(cin>>ch && ch[0]!='#')
	{
		v.push_back(ch);
		solve(ch);
		_++;
	}
    sort(v.begin(),v.end());
	F(i,0,_-1)
		if(M[ss(v[i])]==1) cout<<v[i]<<endl;
    return 0;
}






