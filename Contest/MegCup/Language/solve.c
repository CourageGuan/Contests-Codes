#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

int yes(char *a)
{
	char s[8][5] = {" the"," of "," and"," on ","you"," we ","his","3."};
	int j=0;
	for(;j<9;++j) if(strstr(a,s[j])) return 1;
	return 0;
}


int main()
{
	freopen("all.txt","r",stdin);
	char s[110];
	int mx = 0,mn = 100;
	int cnt = 0;
	for(int i=1;i<=100;++i)
	{
		gets(s);
		int cur = yes(s);
		if(!cur)
		{
			printf("%d\n",i);
			++cnt;
		}
	}
	printf("\n..%d\n",cnt);
	puts(" ====== ");
	for(int i=1;i<=100;++i)
	{
		gets(s);
		int cur = yes(s);
		if(cur)
		{
		   	printf("%d\n",i);
		}
	}
	return 0;
}

