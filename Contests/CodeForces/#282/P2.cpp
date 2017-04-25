#include<cstdio>

int main()
{
  int a,b;
  int ans;
  //freopen("test","r",stdin);
  scanf("%d%d",&a,&b);
  if(b>a)
  {
    printf("0");
    return 0;
  }
  if (b==a)
  {
    printf("infinity");
    return 0;
  }
  if (a-b==1)
  {
    printf("1");
    return 0;
  }
    ans=0;
    for(int i=1;i*i<=a-b;i++)
    {
      if((a-b)%i==0&&i>b) ans++;
      if((a-b)%i==0&&(a-b)/i>b&&i*i!=(a-b)) ans++;
    }
    printf("%d",ans);
    return 0;
}
