#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define maxN 15

void deal(void);
void print(int kase);

bool H[maxN][maxN],V[maxN][maxN];
int n;
int ans[maxN];

int main()
{
  //freopen("test","r",stdin);
  //freopen("s.out","w",stdout);
  int kase=0;
  while(scanf("%d",&n)==1)
  {
   kase++;
   if(kase>1) printf("\n**********************************\n\n");
   int m;
   memset(H,false,sizeof(H));
   memset(V,false,sizeof(V));
   scanf("%d",&m);
   for(int i=0;i<m;i++)
   {
      char ch[2];
      int y,x;
      scanf("%s%d%d",ch,&y,&x);
      if(ch[0]=='H') H[y][x]=true;
      else V[y][x]=true;
   }
   deal();
   print(kase);
  }
  return 0;
}

void deal(void)
{
  memset(ans,0,sizeof(ans));
  int t,y,x,i;
  bool flag=true;
  for(t=1;t<n;t++)
    for(y=1;y<=n-t;y++)
      for(x=1;x<=n-t;x++)
      {
        flag=true;
        for(i=0;i<t;i++)
        if(H[y][x+i]==false||V[x][y+i]==false||H[y+t][x+i]==false||V[x+t][y+i]==false)
        {
          flag=false;
          break;
	  		}
	  		if(flag)
				{
					//printf("%d:(%d,%d)\n",t,y,x);
					ans[t]++;
				}
	  	}
}

void print(int kase)
{
	int i;
	bool flag=false;
	printf("Problem #%d\n\n",kase);
	for(i=1;i<n;i++)
	  if(ans[i])
		{
			printf("%d square (s) of size %d\n",ans[i],i);
			flag=true;
		}
	if(!flag) printf("No completed squares can be found.\n");
}
