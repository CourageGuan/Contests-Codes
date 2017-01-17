#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const double pi = acos(-1.0);
const double eps = 1e-6;
int T,p,x,y;

int dis(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

bool judge()
{
	if(p == 0 || dis(x,y,50,50) > 50*50) return 0;
	int a = dis(x,y,50,50),b = 50*50,c = dis(x,y,50,100);
	if((x == 50 && y >= 50) || a == 0) return 1;
	double ang = acos((a + b - c)/2/sqrt(a*b));
	if(x < 50) ang += pi;
	if(ang/pi*50 > p) return 0;
	return 1;
}

void solve()
{
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d %d %d",&p,&x,&y);
		printf("Case #%d: %s\n",z,judge()?"black":"white");
	}

}

int main()
{
//	freopen("input.txt","r",stdin);
	freopen("progress_pie.txt","r",stdin);
	freopen("a.txt","w",stdout);
	solve();
	return 0;
}
