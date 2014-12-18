#include<cstdio>


const int ans[10]={2,7,2,3,3,4,2,5,1,2};

int main()
{
  char n[2];
  scanf("%s",n);
  printf("%d",ans[n[0]-'0']*ans[n[1]-'0']);
  return 0;
}








