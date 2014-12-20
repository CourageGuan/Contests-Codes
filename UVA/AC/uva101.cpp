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
  //printf("\n");
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
  //getchar();
  char ch[10],ch1[10];
  F(i,0,n-1)
  {
	map[i]=i;
	block[i].push_back(i);
	//C(block[i].size());
  }
  int a,b;
  while(scanf("%s%d%s%d",&ch,&a,&ch1,&b)==4 && ch[0]!='q')
  {
    //C(ch);
	int kase=0;
	if(a==b) continue;
    if(ch[0]=='m') kase++;
	else kase+=3;
	if(ch1[1]=='v') kase++; 
	solve(a,b,kase);
    //print();//break;
  }
  print();
  //F(i,0,n) C(map[i]);
  return 0;
}





