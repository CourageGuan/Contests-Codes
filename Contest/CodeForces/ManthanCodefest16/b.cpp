#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int m;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&m);
	int t = 0,cnt = 0;
	for(int i=1;;++i)
	{
		t += 5;
		++cnt;
		int p = i;
		while(p%5 == 0) p/=5,++cnt;
		if(cnt == m) break;
		if(cnt > m)
		{
			puts("0");
			return 0;
		}
	}
	printf("%d\n",5);
	for(int i=t;i<t+5;++i) printf("%d ",i);
	return 0;
}

