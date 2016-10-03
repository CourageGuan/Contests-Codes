#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2200;
int f[maxn],n;
int d[maxn];

inline void update(int &x,int y)
{
	if(x < y)
		x = y;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		F(i,1,n-1) scanf("%d",f+i);
		memset(d,0,sizeof d);
		d[0] = n*f[1];
		F(j,1,n-2)
		{
			F(i,0,n-2-j)
				update(d[i+j],d[i]+f[j+1]-f[1]);
		}
		printf("%d\n",d[n-2]);
	}
	return 0;
}
