#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
double d[maxn][maxn];
int w,b;

int main()
{
	while(cin >> w >> b)
	{
		if(!w && !b)
		{
			puts("0.0000000000");
			continue;
		}
		double res = 1.0*w/(w+b);
		memset(d,0,sizeof d);
		d[w][b] = 1;
		for(int x=w;x>=1;--x)
		{
			for(int y=b;y>=0;--y)
			{
				if(x == w && y == b) continue;
				if((w+b-x-y)%3 <= 1)
					d[x][y] += d[x][y+1]*(y+1)/(x+y+1);
				else
					d[x][y] += d[x+1][y]*(x+1)/(x+1+y) + d[x][y+1]*(y+1)/(x+y+1);

				if((w+b-x-y)%3 == 0)
					res += d[x][y]*x/(x+y);
			}
		}
		printf("%.10lf\n",res);
	}
	return 0;
}
