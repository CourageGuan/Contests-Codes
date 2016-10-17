#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
char s[maxn];

int main()
{
	scanf("%s",s);
	int n = strlen(s),S = 0,res = n;
	for(int i=0;i<n;++i)
	{
		if(s[i] == 'S') S++;
		else
		{
			if(S) S--,res -= 2;
		}
	}
	printf("%d\n",res);
	return 0;
}
