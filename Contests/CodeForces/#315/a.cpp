#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int T,S,q;

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d %d",&T,&S,&q)==3)
	{
		int pre = 0;
		int cnt = 1;
		for(int t=S+1;t<=T;++t)
		{
			int now = t*(q-1);
			pre +=q;
			if(pre>=now)
			{
				if(pre==now && t==T) continue;
			   	++cnt;
				pre = 0;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
