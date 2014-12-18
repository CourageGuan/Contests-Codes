#include<cstdio>
#include<stack>
#include<cstring>
#include<iostream>
using namespace std;

stack<int> yy;
stack<int> xx;  //记录棋子坐标

int pic[12][11];
bool f[12][11];
bool flag;
int dx[8]={-1,1,-2,-2,-1,1,2,2},dy[8]={-2,-2,-1,1,2,2,-1,1};
    //０上左 １上右 ２左上 ３左下 ４下左 ５下右 ６右上 ７右下

void deal(int kase,int y,int x);

int main()
{
  //freopen("/home/alex/桌面/test","r",stdin);
  int x1,y1,n;  //y1,x1 黑将坐标
  while(scanf("%d%d%d",&n,&y1,&x1)==3&&n)
  {
    flag=false;
    //int xx[100],yy[100],len=0;
    while(!xx.empty()) xx.pop();
    while(!yy.empty()) yy.pop();
    //memset(xx,0,sizeof(xx));
    //memset(yy,0,sizeof(yy));
    memset(f,false,sizeof(f));
    memset(pic,0,sizeof(pic));// 空白 ０
    pic[y1][x1]=-1;  //黑将 -1
    for(int i=1;i<=3;i++)
      for(int j=4;j<=6;j++)
        f[i][j]=true;
    for(int i=0;i<n;i++)
    {
      char ch;
      int y,x;
      cin>>ch>>y>>x;
      //scanf("%c%*c%d %d",&ch,&y,&x);
      xx.push(x);
      yy.push(y);
      //xx[len]=x;yy[len++]=y;
      switch(ch)
      {
        case 'G':pic[y][x]=1;break;  //帅 １
        case 'R':pic[y][x]=2;break;  //车 ２
        case 'H':pic[y][x]=3;break;  //马 ３
        case 'C':pic[y][x]=4;break;  //炮 ４
      }
    }
   /*for(int i=1;i<=10;i++)
    { for(int j=1;j<=9;j++)
        cout<<pic[i][j]<<" ";
      cout<<endl;
    }
    cout<<endl;*/
    while(!xx.empty()&&!yy.empty())
    //while(len--)
    {
      int a,b;
      b=xx.top();xx.pop();
      a=yy.top();yy.pop();
      //b=xx[len];a=yy[len];
      deal(pic[a][b],a,b);
    }
    /*for(int i=1;i<=10;i++)
    { for(int j=1;j<=9;j++)
        cout<<f[i][j]<<" ";
      cout<<endl;
    }*/
    if(f[y1+1][x1]||f[y1-1][x1]||f[y1][x1+1]||f[y1][x1-1]) flag=true;
    if(!flag) puts("YES");
    else puts("NO");
  }
  return 0;
}


void deal(const int kase,const int y,const int x)
{
  switch(kase)
  {
    case 1:  //帅
      for(int j=y-1;j>=1;j--)
      {
        f[j][x]=false;
        if(pic[j][x]==-1) {flag=true;return;}  //老将照面
        if(pic[j][x]>0) break;
      }
      break;
    case 2:  //车
      for(int i=x+1;i<=9;i++)
      {f[y][i]=false;if(pic[y][i]>0) break;}
      for(int i=x-1;i>=1;i--)
      {f[y][i]=false;if(pic[y][i]>0) break;}
      for(int j=y+1;j<=10;j++)
      {f[j][x]=false;if(pic[j][x]>0) break;}
      for(int j=y-1;j>=1;j--)
      {f[j][x]=false;if(pic[j][x]>0) break;}
      break;
    case 4:  //炮
    {
      int cflag=0;
      for(int i=x+1;cflag<2&&i<=9;i++)
      {
        if(cflag==1) f[y][i]=false;
        if(pic[y][i]>0) cflag++;
      }
      cflag=0;
      for(int i=x-1;cflag<2&&i>=1;i--)
      {
        if(cflag==1) f[y][i]=false;
        if(pic[y][i]>0) cflag++;
      }
      cflag=0;
      for(int j=y+1;cflag<2&&j<=10;j++)
      {
        if(cflag==1) f[j][x]=false;
        if(pic[j][x]>0) cflag++;
      }
      cflag=0;
      for(int j=y-1;cflag<2&&j>=1;j--)
      {
        if(cflag==1) f[j][x]=false;
        if(pic[j][x]>0) cflag++;
      }
      break;
    }
    case 3:  //马
    {
      int i;
      for(i=0;i<=7;i++)
      {
        if(x+dx[i]<=9&&x+dx[i]>=1&&y+dy[i]<=10&&y+dy[i]>=1)
        {
          if(!pic[y+dy[i]+1][x]&&i<2)
            f[y+dy[i]][x+dx[i]]=false;
          if(!pic[y][x+dx[i]+1]&&i>1&&i<4)
            f[y+dy[i]][x+dx[i]]=false;
          if(!pic[y+dy[i]-1][x]&&i>3&&i<6)
            f[y+dy[i]][x+dx[i]]=false;
          if(!pic[y][x+dx[i]-1]&&i>5)
            f[y+dy[i]][x+dx[i]]=false;
        }
      }
    break;
   }
  }
}
