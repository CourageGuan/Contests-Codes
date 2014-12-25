#include<cstdio>
#include<utility>
#include<set>
#include<cstring>
#include<iostream>
#define N 10
using namespace std;

const int dx[8]={0,0,-1,1,-1,1,-1,1},dy[8]={-1,1,0,0,-1,-1,1,1};

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
  //freopen("test","r",stdin);
  //freopen("1","w",stdout);
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
    //scanf("%c",now);
    cin>>now;
    //cout<<now<<endl;
    char ch[5];
    while(scanf("%s",ch)==1)
    {
      if(ch[0]=='L')
      dealL(now,0);
      if(ch[0]=='M')
      {
        int a=ch[1]-'0',b=ch[2]-'0';
        dealM(now,a,b);
        now=(now=='B')?'W':'B';
      }
      if(ch[0]=='Q')
      {print();break;}
    }
    if(n>0) printf("\n");
  }
  return 0;
}

bool dealL(char now,bool flag)
{
  /*for(int i=0;i<=9;i++)
    { for(int j=0;j<=9;j++)
        printf("%d",pic[i][j]);
      printf("\n");
    }*/
  set< pair<int,int> >s;
  s.clear();
  int color=(now=='B')?1:2,ucolor=(now=='W')?1:2;
  //cout<<ucolor<<endl;
  for(int i=1;i<=8;i++)  //search all pic,when meet disk,deal;
    for(int j=1;j<=8;j++)
    {
      if(pic[i][j]==color)
      for(int k=0;k<8;k++)  //8 dirctions
      {
        int num=0;
        int x=i+dx[k],y=j+dy[k];
        //cout<<x<<y<<endl;
        while(x>0&&x<9&&y>0&&y<9)
        {
          if(pic[x][y]==ucolor) num++;
          else break;
          if(num==0) break;
          //cout<<k<<" "<<num<<": "<<x<<","<<y<<endl;
          if(num&&pic[x+dx[k]][y+dy[k]]==0&&x+dx[k]>0&&x+dx[k]<9&&y+dy[k]>0&&y+dy[k]<9)
          {
            pair<int,int> p;
            //cout<<k<<" "<<num<<": "<<x<<","<<y<<endl;
            p.first=x+dx[k];
            p.second=y+dy[k];
            s.insert(p);
            break;
          }
          x+=dx[k];y+=dy[k];
        }
      }
    }
  if(flag) return s.empty();
  if(s.empty())
  {
    printf("No legal move.\n");
    return 0;
  }
  set< pair<int,int> >::iterator it;
  //cout<<s.end()->first;
  for(it=s.begin();it!=s.end();++it)
  if(it!=s.begin())
    printf(" (%d,%d)",it->first,it->second);
  else
    printf("(%d,%d)",it->first,it->second);
  printf("\n");
  return 1;
}

void dealM(char &now,int a,int b)
{
  if(dealL(now,1)) now=(now=='B')?'W':'B';
  int color=(now=='B')?1:2,ucolor=(now=='W')?1:2;
  pic[a][b]=color;
  (now=='B')?numb++:numw++;
  //cout<<now<<endl;
  for(int k=0;k<8;k++)
  {
    int num=0;
    int x=a+dx[k],y=b+dy[k];
    while(x>0&&x<9&&y>0&&y<9)
    {
      if(pic[x][y]==ucolor) num++;
      if(!num) break;
      if(x+dx[k]==0||x+dx[k]==9||y+dy[k]==0||y+dy[k]==9) num=0;
      if(num&&pic[x+dx[k]][y+dy[k]]==color&&x+dx[k]>0&&x+dx[k]<9&&y+dy[k]>0&&y+dy[k]<9) break;
      x+=dx[k];y+=dy[k];
    }
    //printf("%d\n",num);
    if(color==1)
    {numb+=num;numw-=num;}
    else{numw+=num;numb-=num;}
    while(num--)
    {
      pic[x][y]=color;
      x-=dx[k];y-=dy[k];
    }
  }
  printf("Black -%3d White -%3d\n",numb,numw);
}
