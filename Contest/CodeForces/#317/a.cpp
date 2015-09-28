#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;

int main()
{
//	freopen("test.txt","r",stdin);
	int na,nb;
	int m,k;
	scanf("%d %d",&na,&nb);
	scanf("%d %d",&k,&m);
	int ra = INF,rb = -INF;
	for(int i=1;i<=na;++i)
	{
		int x;
		scanf("%d",&x);
		if(i==k) ra = x;
	}
	for(int i=1;i<=nb;++i)
	{
		int x;
		scanf("%d",&x);
		if(nb - i + 1 == m) rb = x;
	}
//	printf("%d %d\n",ra,rb);
	puts(ra<rb?"YES":"NO");
	return 0;
}
