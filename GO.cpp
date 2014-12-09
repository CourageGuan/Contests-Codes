#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=25;

int pic[N][N],tpic[N][N]; //pic 记录图的状态，　tpic　用于dfs的标记
int num;  // 记录被吃棋子数
int numB,numW,repeat;
int n,m;
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};  //0 1 2 3  up down left right

bool dfs(int x,int y,int par1,int par2);
void deal(int kase,int x,int y);

int main()
{
  //freopen("C:\\Users\\Administrator\\Desktop\\data\\test.txt","r",stdin);
  while(cin>>n>>m&&n!=0)
  {
    int i,j;
    numB=numW=0;
    for(i=0;i<=n+1;i++)    //初始化　边缘　-1
      for(j=0;j<=n+1;j++)
      {
        if(i==0||j==0||i==n+1||j==n+1)
				{
				  pic[i][j]=-1;
				  tpic[i][j]=-1;
				}
				else
				{
				  pic[i][j]=0;
				  tpic[i][j]=0;
				}
      }
	for(i=0;i<m;i++)
    {
      char s[20];
      int x,y; //par -1 边缘 0 空白　１　黑色　２　白色　３　标记　
      cin>>s;
	  if(s[2]=='-') x=-(s[3]-'0');
		else x=s[2]-'0';
		if(s[2]=='-')
	       if(s[5]=='-') y=-(s[6]-'0');
		   else y=s[5]-'0';
		else if (s[4]=='-') y=-(s[5]-'0');
			  else y=s[4]-'0';
	    x+=n/2+1;
		y+=n/2+1;
		tpic[x][y]=pic[x][y]=(s[0]=='B')?1:2;
		deal(pic[x][y],x,y);
		for(int j=0;j<4;j++)  //处理相邻不同色情况
		{
		  if(pic[x+dx[j]][y+dy[j]]==2&&pic[x][y]==1)
		  {
			deal(pic[x+dx[j]][y+dy[j]],x+dx[j],y+dy[j]);
	      }
		  if(pic[x+dx[j]][y+dy[j]]==1&&pic[x][y]==2)
		  {
		  	//puts("ok");
			deal(pic[x+dx[j]][y+dy[j]],x+dx[j],y+dy[j]);
	      }
		}//cout<<numB<<" "<<numW<<endl;
    }
    memcpy(tpic,pic,sizeof(pic));
    /*for(i=0;i<=n+1;i++)
    {for(j=0;j<=n+1;j++)
      cout<<pic[i][j]<<" ";
     cout<<endl;
    }*/
    for(i=1;i<=n;i++)    //统计空白
	  for(j=1;j<=n;j++)
        if(tpic[i][j]==0)
        {
          deal(0,i,j);  //黑色占领
          //deal(3,i,j);  //白色占领 
        }
   for(i=1;i<=n;i++)    
	  for(j=1;j<=n;j++)
        if(tpic[i][j]==4)
        {
          numB++;
		}
	/*for(i=0;i<=n+1;i++)
    {for(j=0;j<=n+1;j++)
     cout<<tpic[i][j]<<" ";
     cout<<endl;
    }*/
	memcpy(tpic,pic,sizeof(pic));
    for(i=1;i<=n;i++)    //统计空白
	  for(j=1;j<=n;j++)
        if(tpic[i][j]==0)
        {
          //deal(0,i,j);  //黑色占领
          deal(3,i,j);  //白色占领 
        }
    for(i=1;i<=n;i++)    //统计空白
	  for(j=1;j<=n;j++)
        if(tpic[i][j]==5)
        {
          numW++;
		}
	/*for(i=0;i<=n+1;i++)
    {for(j=0;j<=n+1;j++)
     cout<<tpic[i][j]<<" ";
     cout<<endl;
    }
    /*for(i=0;i<=n+1;i++)
    for(j=0;j<=n+1;j++)
    {
      cout<<pic[i][j]<<" ";
     cout<<endl;
    }*/
    cout<<numB<<" "<<numW<<endl;
  }
  return 0;
}

void deal(int kase,int x,int y)
{
  num=1;
  switch(kase)
  {
    case 1:
      if (dfs(x,y,1,0))
      {
        numW+=num;
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            if(tpic[i][j]==3)
            {
              pic[i][j]=0;
              tpic[i][j]=0;
            }
			}
			else
			{
			  for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            if(tpic[i][j]==3)
            {
              //pic[i][j]=1;
              tpic[i][j]=1;
            }
			}
	  num=0;
      break;
    case 2:
      if (dfs(x,y,2,0))
      {
        numB+=num;
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            if(tpic[i][j]==3)
            {
              pic[i][j]=0;
              tpic[i][j]=0;
            }
	  }
			else
			{
			  for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            if(tpic[i][j]==3)
            {
              //pic[i][j]=2;
              tpic[i][j]=2;
            }
			}
	  num=0;
      break;
    case 0: 
	  if(dfs(x,y,0,2))
      {
        //numB+=num;
        //if(num>n/2)repeat=num;
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            if(tpic[i][j]==3)
            {
              //pic[i][j]=3;
              tpic[i][j]=4;
            }
      }
	  else
		for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            if(tpic[i][j]==3)
            {
               //pic[i][j]=0;
               tpic[i][j]=0;
            }
	  //num=1;
      break;
    case 3:
		  if (dfs(x,y,0,1))
      {
        //numW+=num;
        //if(num>n/2)repeat=num;
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            if(tpic[i][j]==3)
            {
              //pic[i][j]=3;
              tpic[i][j]=5;
            }
	  }
			else
		for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            if(tpic[i][j]==3)
            {
              //pic[i][j]=0;
              tpic[i][j]=0;
            }
			//num=1;
      break;
  }
}


// true 棋子被吃　　false 棋子未被吃　
bool dfs(int x,int y,int par1,int par2)  // par1 相同颜色  par2　跳出颜色
{
  int i;
  bool flag=1;
  tpic[x][y]=3;
  for(i=0;i<4;i++)
    if(tpic[x+dx[i]][y+dy[i]]==par2) return 0;
  for(i=0;i<4;i++)
    if(tpic[x+dx[i]][y+dy[i]]==par1)
    {
      num++;
      flag&=dfs(x+dx[i],y+dy[i],par1,par2);
    }
    return flag;
}

