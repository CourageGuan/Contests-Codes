#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL x;
	scanf("%lld",&x);
	x = -x;
	x %= 360;
	int p[4];
	p[0] = abs(x);
	p[1] = abs((x+90)%360);
	p[2] = abs((x+180)%360);
	p[3] = abs((x+270)%360);
	int cur = 360,pos = 0;
	for(int i=0;i<4;++i)
	{
		p[i] = min(p[i],360-p[i]);
	//	printf("%d\n",p[i]);
		if(p[i] < cur)
		{
			cur = p[i];
			pos = i;
		}
	}
	printf("%d\n",pos);
	return 0;
}
