#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 1e5 + 10;
char s[maxn],ss[maxn];
int n,k;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);	
	scanf("%s",s);
	for(int i=0;i<n;++i)
	{
		if(!k)
		{
			ss[i] = s[i];
			continue;
		}
		if(s[i] - 'a' >= 'z' - s[i])
		{
			if(s[i] - 'a' <= k)
			{
				k -= s[i] - 'a';
				ss[i] = 'a';
			}
			else
			{
				ss[i] = s[i] - k;
				k = 0;
			}

		}
		else
		{
			if('z' - s[i] <= k)
			{
				k -= 'z' - s[i];
				ss[i] = 'z';
			}
			else
			{
				ss[i] = s[i] + k;
				k = 0;
			}

		}
	}
	puts(k?"-1":ss);
	return 0;
}


