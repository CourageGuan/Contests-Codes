#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

char s[20],ss[20];
const int ten[6] = {0,10000,110000,1110000,11110000,111110000};

int toInt(char *s)
{
	int res = 0;
	for(int i=0;i<strlen(s);++i)
		res = res * 10 + s[i] - '0';
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%s",ss);
		for(int j=4;j<=strlen(ss);++j) s[j-4] = ss[j];
		int len = strlen(s),cur = toInt(s);
		if(len == 1)
		{
			if(s[0] == '9')
				puts("1989");
			else
				printf("199%s\n",s);
		}
		if(len == 2)
		{
			if(strcmp(s,"99") == 0)
				puts("1999");
			else
				printf("20%s\n",s);
		}
		if(len == 3)
		{
			if(cur >= 99)
				printf("2%s\n",s);
			else
				printf("3%s\n",s);
		}
		if(len >= 4)
		{
			if(cur < 3099 + ten[len-4])
				printf("1%s\n",s);
			else
				printf("%s\n",s);
		}
	}
	return 0;
}
