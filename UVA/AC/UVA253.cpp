#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;i++)
#define C(a) cout<<a<<endl;
#define debug puts("DEBUG")
#define FRER freopen("253.in","r",stdin)
#define FREW freopen("253.out","r",stdout)
#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;}

const int sh[24][6]={{0,1,2,3,4,5},{0,3,1,4,2,5},{0,4,3,2,1,5},{0,2,4,1,3,5},
                     {1,5,2,3,0,4},{1,3,5,0,2,4},{1,0,3,2,5,4},{1,2,0,5,3,4},
                     {2,1,5,0,4,3},{2,0,1,4,5,3},{2,4,0,5,1,3},{2,5,4,1,0,3},
                     {3,1,0,5,4,2},{3,5,1,4,0,2},{3,4,5,0,1,2},{3,0,4,1,5,2},
                     {4,0,2,3,5,1},{4,3,0,5,2,1},{4,5,3,2,0,1},{4,2,5,0,3,1},
                     {5,4,2,3,1,0},{5,3,4,1,2,0},{5,1,3,2,4,0},{5,2,1,4,3,0}};
                     //24 Status of cube


char s[20];

void solve(void)
{
    //debug;
    char s1[10],s2[10];
    F(i,0,5) s1[i]=s[i];
    F(i,6,11) s2[i-6]=s[i];
    char ss[10];
    //debug;
    F(i,0,23)
    {
      F(j,0,5) ss[j]=s1[sh[i][j]];
      if(strcmp(ss,s2)==0) {printf("TRUE\n");return;}
    }
    //debug;
    //PM(ss,23,5) cout<<endl;
    //C(s2);
    printf("FALSE\n");
}

int main()
{
  //FRER;
  //int _=0;
  while(scanf("%s",s)==1)
  {/*if(_++) printf("\n");*/solve();}
  return 0;
}
