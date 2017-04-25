#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	while(scanf("%d",&n) == 1)
	{
		char s[2];
		int cur = 0,x,ans = 0;
		R(i,n)
		{
			scanf("%s",s);
			if(s[0] == 'S')
			{
			   	cur = 0;
				++ans;
			}
			else
			{
				scanf("%d",&x);
				if(x == 1) ++ans;
			}
		}
		if(cur) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}
