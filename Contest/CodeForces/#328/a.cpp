#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;

char s[10][10];
int pa[10],pb[10];

int main()
{
	//freopen("test.txt","r",stdin);
	memset(pa,INF,sizeof pa);
	memset(pb,-1,sizeof pb);

	for(int i=0;i<8;++i)
	{
		scanf("%s",s[i]);
		for(int j=0;j<8;++j)
		{
			if(s[i][j] == 'W') pa[j] = min(pa[j],i);
			if(s[i][j] == 'B') pb[j] = max(pb[j],i);
		}
	}
	int ansa,ansb;
	ansa = ansb = INF;

	for(int i=0;i<8;++i)
	{
		bool flag = true;
		if(pa[i] != INF)
		{
			for(int j=pa[i]-1;j>=0;--j) if(s[j][i] != '.') { flag = false; break; }
			if(flag) ansa = min(ansa,pa[i]);
		}
		if(pb[i] != -1)
		{
			flag = true;
			for(int j=pb[i]+1;j<8;++j) if(s[j][i] != '.') { flag = false; break; }
			if(flag) ansb = min(ansb,8-pb[i]-1);
		}
	}
	puts(ansa <= ansb?"A":"B");
	return 0;
}
