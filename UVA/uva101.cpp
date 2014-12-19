/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 & Author: GYH
 & Created Time:  2014/12/19 13:51:35
 & File Name:uva101.cpp
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
//#include <map>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
//typedef map<string,int> MSI;
//typedef map<int,int> MII;
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

template<typename T>
bool cmp(T a,T b){return a>b;}

const int inf = 0x7fffffff;
const int _inf= 0x8fffffff;
const LL  INF = 1e18;
const double EPS = 1e-8;
const double pi = acos(-1.0);
const int N=30  ;//The Range of Description

/*
  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux
                                                                          */
VI block[N];
int map[N];
int n;

void print()
{
  F(i,0,n-1)
  {
	printf("%d:",i);
	//C(block[i].size());
	F(j,1,block[i].size())
	  printf(" %d",block[i][j-1]);
	printf("\n");
  }
}

void ret(int a)  //return blocks
{
  int loc=map[a];
  int locs;
  //if(block[loc].empty()) return;
  F(i,0,block[loc].size())
    if (block[loc][i]==a){
	locs=i;
	break;
	}
	//C(block[loc][1]);
  F(i,locs+1,block[loc].size()-1)
	{
    int b=block[loc][i];
	  map[b]=b;
	  block[b].push_back(b);
	  //cout<<"?";C(b);
  }
  block[loc].resize(locs+1);
  //print();
}

void mv(int a,int b)  //move blocks
{
  //DEBUG;
  int loc=map[a],locb=map[b],locs;
  //C(loc);C(locb);
  //if(block[loc].empty()) return;
  //DEBUG;
  F(i,0,block[loc].size())
    if (block[loc][i]==a){
	locs=i;
	break;
	}
	//DEBUG;
	//C(block[locb].size());
	//C(locs);
  F(i,locs,block[loc].size()-1)
  {
	map[block[loc][i]]=map[b];
	block[locb].push_back(block[loc][i]);
  }
  block[loc].resize(locs);
  //DEBUG;
}

void solve(int a,int b,int kase)
{
 //C(a);C(b);C(kase);

 if (map[b]==map[a]) return;
 //DEBUG;
 switch(kase)
 {
   case 1:ret(a);ret(b);mv(a,b);break;
   case 2:ret(a);mv(a,b);break;
   case 3:ret(b);mv(a,b);break;
   case 4:mv(a,b);break;
 }
}

int main()
{
  //FRER;
  //FREW;
  scanf("%d",&n);
  getchar();
  char ch[30];
  F(i,0,n-1)
  {
	map[i]=i;
	block[i].push_back(i);
	//C(block[i].size());
  }
  while(scanf("%[^\n]%*c",&ch)==1 && ch[0]!='q')
  {
    //C(ch);
	int a=-1,b=0;
	int kase=0,len=strlen(ch);
    if(ch[0]=='m') kase++;
	else kase+=3;
	F(i,4,len)
	  if(isdigit(ch[i]))
	    if(a==-1) a=ch[i]-'0';
	    else b=ch[i]-'0';
	  else
		if(ch[i]=='o' && ch[i+1]=='v') kase++;
		//C(a);C(b);C(kase);
		if(a==b) continue;
    solve(a,b,kase);
    //print();//break;
  }
  print();
  //F(i,0,n) C(map[i]);
  return 0;
}





