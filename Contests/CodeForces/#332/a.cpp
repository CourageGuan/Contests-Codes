#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;

const int INF = 0x3f3f3f3f;

int main()
{
	//freopen("test.txt","r",stdin);
	int d[3]; 
	for(int i=0;i<3;++i) scanf("%d",d+i);
	int ans = INF;
	ans = min(ans,d[0]*2+d[1]*2);
	ans = min(ans,d[0]+d[1]+d[2]);
	ans = min(ans,(d[0]+d[2])*2);
	ans = min(ans,(d[1]+d[2])*2);
	printf("%d\n",ans);
	return 0;
}
