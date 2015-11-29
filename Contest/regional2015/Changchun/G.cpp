#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 110;
int x[maxn],y[maxn],d[maxn];

bool yes()
{
	for(int i=1;i<4;++i)
	{
		if(d[i] != d[i-1]) return false;
	}
	if(d[4] != d[5]) return false;
	if(2*d[0] != d[4]) return false;
	return true;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d %d",x+i,y+i);
		}
		if(n!=4)
		{
			puts("NO");
		}
		else
		{
			int cnt = 0;
			for(int i=0;i<4;++i)
				for(int j = i+1;j<4;++j)
				{
					d[cnt++] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
				}
			sort(d,d+cnt);
			puts(yes()?"YES":"NO");
		}
	}
	return 0;
}
