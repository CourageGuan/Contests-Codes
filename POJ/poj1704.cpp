//str
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1010;
int save[maxn];

int main()
{
	int T,n;
	//freopen("test.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans = 0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",save+i);
		}
		if(n&1) save[n++] = 0;
		sort(save,save+n);
		for(int i=1;i<n;i+=2)
		{
			ans ^= (save[i] - save[i-1]  - 1);
		}
		printf("%s will win\n",ans?"Georgia":"Bob");
	}
	return 0;
}
