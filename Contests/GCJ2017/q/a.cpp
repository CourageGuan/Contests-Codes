#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
int n,k;
char s[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%s %d",s,&k);
		n = strlen(s);
		int ans = 0;
		for(int i=0;i+k<=n;++i)
		{
			if(s[i] == '-')
			{
				++ans;
				for(int j=0;j<k;++j)
				{
					if(s[i+j] == '-')
						s[i+j] = '+';
					else
						s[i+j] = '-';
				}
			}
		}
		//puts(s);
		printf("Case #%d: ",z);
		bool flag = 1;
		for(int i=n-k;i<n;++i) if(s[i] == '-')
		{
			flag = 0;
			puts("IMPOSSIBLE");
			break;
		}
		if(flag) printf("%d\n",ans);
	}
	return 0;
}
