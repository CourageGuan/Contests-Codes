#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=1000;

struct ed{
  int a,b,c,id;
  bool operator <(const ed & rhs) const {
     if(c!=rhs.c) return c>rhs.c;
     if(b!=rhs.b) return b<rhs.b;
     return id<rhs.id;
  }
} p[maxn];

int main()
{
  int m,n;
  while(cin>>n){
    for(int i=0;i<n;++i){
      cin>>p[i].a>>p[i].b;
      p[i].c=p[i].a-p[i].b;
      p[i].id=i;
    }
    sort(p,p+n);
    for(int i=0;i<n;++i){
     if(i) printf(" ");
     printf("%d",p[i].id);
    }
    puts("");
  }       
  return 0;
}