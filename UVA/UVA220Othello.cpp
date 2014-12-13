#include<cstdio>
#include<utility>
#include<set>
#include<cstring>
#define N 10
using namespace std;

const int dx[8]={0,1,1,1,0,-1,-1,-1},dy[8]={-1,-1,0,1,1,1,0,-1};
//shunshizhen 0 up 1 upright 2 right 3 downright 4 down 5 downleft 6 left 7 upleft

//pair<int,int> p;
//set< pair<int,int> >s;

int pic[N][N];  // - 0  B 1  W 2
int numb,numw;  //record num of disk

bool dealL(char now,bool flag);  //flag is_print
void dealM(char &now,int a,int b);

void print()
{
  for(int i=1;i<=8;i++)
  {
    for(int j=1;j<=8;j++)
      switch(pic[i][j])
      {
        case 0:printf("-");break;
        case 1:printf("B");break;
        case 2:printf("W");break;
      }
    printf("\n");
  }
}


int main()
{
  freopen("/home/alex/桌面/test","r",stdin);
  int n;
  scanf("%d",&n);
  while(n--)
  {
    numw=numb=0;
    memset(pic,0,sizeof(pic));
    for(int i=1;i<=8;i++)
    {
      char s[10];
      scanf("%s",s);
      for(int j=0;j<=7;j++)
        if(s[j]!='-')
        {
          pic[i][j+1]=(s[j]=='B')?1:2;
          (s[j]=='B')?numb++:numw++;
        }
    }
    /*for(int i=0;i<=9;i++)
    { for(int j=0;j<=9;j++)
        printf("%d",pic[i][j]);
      printf("\n");
    }*/
    char now;
    scanf("%c",&now);
    char ch[5];
    while(scanf("%s",ch)==1)
    {
      if(ch[0]=='Q')
      {print();break;}
      if(ch[0]=='L')
      dealL(now,0);
      if(ch[0]=='M')
      {
        int a=ch[1]-'0',b=ch[2]-'0';
        dealM(now,a,b);
      }
    }
    printf("\n");
  }
  return 0;
}

bool dealL(char now,bool flag)
{
  set< pair<int,int> >s;
  pair<int,int> p;
  s.clear();
  int color=(now=='B')?1:2,ucolor=(now=='W')?1:2;
  for(int i=1;i<=8;i++)  //search all pic,when meet disk,deal;
    for(int j=1;j<=8;j++)
    {
      if(pic[i][j]==color)
      {
        for(int k=0;k<8;k++)  //8 dirctions
        {
          int num=0;
          int x=i+dx[k],y=j+dy[k];
          while(x>0&&x<9&&y>0&&y<9)
          {
            if(pic[x][y]==ucolor) num++;
            if(!num) break;
            if(num&&pic[x+dx[k]][y+dy[k]]==0&&x+dx[k]>0&&x+dx[k]<9&&y+dy[k]>0&&y+dy[k]<9)
            {
              p.first=x+dx[k];
              p.second=y+dy[k];
              s.insert(p);
            }
            x+=dx[k];y+=dy[k];
          }
        }
      }
    }
    if(flag) return (s.empty());
    if(s.empty())
    {
      printf("No legal move.\n");
      return 0;
    }
    set< pair<int,int> >::iterator it;
    for(it=s.begin();it!=s.end();++it)
      printf("(%d,%d) ",it->first,it->second);
    printf("\n");
    return 1;
}

void dealM(char &now,int a,int b)
{
  if(!dealL(now,1)) now=(now=='B')?'W':'B';
  int color=(now=='B')?1:2,ucolor=(now=='W')?1:2;
  pic[a][b]=color;
  (now=='B')?numb++:numw++;
  for(int k=0;k<8;k++)
  {
    int num=0;
    int x=a+dx[k],y=b+dy[k];
    while(x>0&&x<9&&y>0&&y<9)
    {
      if(pic[x][y]==ucolor) num++;
      if(!num) break;
      if(num&&pic[x+dx[k]][y+dy[k]]==color&&x+dx[k]>0&&x+dx[k]<9&&y+dy[k]>0&&y+dy[k]<9) break;
      if(x+dx[k]==0||x+dx[k]==9||y+dy[k]==0||y+dy[k]==9) num=0;
      x+=dx[k];y+=dy[k];
    }
    if(color==1)
    {numb+=num;numw-=num;}
    else{numw+=num;numb-=num;}
  }
  printf("Black -  %d White - %d\n",numb,numw);
}
