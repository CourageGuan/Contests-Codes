/*模拟过程*/
#include<cstdio>
#include<algorithm>

int main()
{
	int m,s,t,sum1=0,sum2=0,sum=0;
    scanf("%d%d%d",&m,&s,&t);
	int i;
	for(i=1;i<=t;i++)
	{
		sum1+=17;
		if(m>=10)
		{
			sum2+=60;
			m-=10;
		}
		else m+=4;
		sum=std::max(sum1,sum2);
		sum1=sum;
		if(sum>=s)
		{
			printf("Yes\n%d\n",i);
			return 0;
		} 
	}	
	if(sum>=s)  printf("Yes\n%d\n",i-1);
	  else  printf("No\n%d\n",sum);
	return 0;
}
