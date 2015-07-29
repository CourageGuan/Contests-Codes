/*
 & Created Time:  Wed 15 Apr 2015 12:34:21 AM CST
 & File Name: c.cpp
 & Author: NoBystander
*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <utility>
using namespace std;


#define LEN(n) (int)log10(n)+1
#define REP(i,n) for(int i=0;i<n;++i)
#define F(i,a,b) for(int i=a;(i)<b;++i)
#define Fd(i,b,a) for(int i=b-1;i>=a;--i)
#define EACH(i,a) for(__typeof((a).begin()) i=a.begin(); i!=a.end(); ++i)

#define FILL(a,t) memset((a),(t),sizeof(a))
#define CLEAR(ST) while(!ST.empty()) ST.pop();
#define all(a) a.begin(),a.end()
#define sz(a) ((int)(a).size())
#define lowbd(a,x) lower_bound(all(a),x) - a.begin()
#define upbd(a,x) upper_bound(all(a),x) - a.begin()
#define pb push_back
#define mp(A,B) make_pair(A,B)
#define fi first
#define se second


typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
typedef long double LDB;
typedef vector<int> VI;
typedef map<string,int> MSI;
typedef map<int,int> MII;
typedef pair<int,int> PII;


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

const int INF = 0x3f3f3f3f;
const LL  LINF = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-9;
const DB PI = acos(-1.0);

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int mv[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

LL nextInt(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	LL res=0;
	while(isdigit(ch)){
		res=res*10+ch-48;
		ch=getchar();
	} return res; }

void write(LL x){
	if(x>9) write(x/10);
	putchar(x%10+48);
}

/*-----  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux  -----*/

ULL n,m,t,l,r,a,b;

ULL pos(ULL i){
	return a+b*(i-1);
}

ULL solve()
{
	if(pos(l)>t) return 0;
	ULL A=pos(l);
	ULL L=l,R=INF,res=l;
	while(L<=R){
		ULL M=(R+L)>>1;
		if((A+pos(M))*(M-l+1)<=2*t*m){
			res=M;
		   	L=M+1;
		}
		else R=M-1;
	}
	res=min(res,(t-a+b)/b);
	return res;
}


int main()
{
	//freopen("test.txt","r",stdin);
  	cin>>a>>b>>n;
	while(n--){
		cin>>l>>t>>m;
		ULL t=solve();
		if(t) cout<<t<<endl;
		else cout<<-1<<endl;
	}
	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

