#include<cstdio>

int d1[9],d2[9];

bool yes()
{
	bool flag = true;
	for(int i=0;i<4;++i) if(d1[i] != d2[i]) flag = false;
	return flag;
}

bool solve()
{
	for(int z=0;z<4;++z)
	{
		if(yes()) return true;
		int t = d1[0];
		d1[0] = d1[2];
		d1[2] = d1[3];
		d1[3] = d1[1];
		d1[1] = t;
	}
	return false;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		for(int i=0;i<4;++i) scanf("%d",d1+i);
		for(int i=0;i<4;++i) scanf("%d",d2+i);
		printf("Case #%d: ",z);
		puts(solve()?"POSSIBLE":"IMPOSSIBLE");
	}
	return 0;
}
