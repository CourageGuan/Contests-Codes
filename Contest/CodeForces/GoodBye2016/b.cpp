#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

int len,t,cur = 0;
char dir[10];


int main()
{
//	freopen("input.txt","r",stdin);
	bool flag = 1;
	scanf("%d",&t);
	F(i,1,t)
	{
		scanf("%d %s",&len,&dir);
		if(!flag) continue;
		if(cur == 0 && dir[0] != 'S')
		{
			flag = 0;
			continue;
		}
		if(cur == 20000 && dir[0] != 'N')
		{
			flag = 0;
			continue;
		}
		if(dir[0] == 'E' || dir[0] == 'W') continue;
		if(dir[0] == 'S') cur += len;
		else cur -= len;
		if(cur < 0 || cur > 20000) flag = 0;
	}
	if(cur != 0) flag = 0;
	puts(flag?"YES":"NO");
	return 0;
}
