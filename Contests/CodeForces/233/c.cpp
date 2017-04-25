#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

LL a,b;

int main()
{
	//	freopen("test.txt","r",stdin);
	cin >> a >> b;
	if(a == 0)
	{
		cout << -b*b << '\n';
		F(i,1,b) putchar('x');
	}
	else
	{
		int p = 0;
		LL mx = -1e18,t,d;
		F(i,0,a-1)
		{
			LL cur = (a - i)*(a-i) + i;
			t = b/(i+2);
			d =  b - t*(i+2);
			cur -= d*(t+1)*(t+1) + (i+2-d)*t*t;
			if(cur > mx) mx = cur,p = i+2;
		}
		cout << mx << '\n';
		t = b/p;
		d = b - t*p;
		F(i,1,d)
		{
			F(j,1,t+1) putchar('x');
			F(j,1,i == 1?a-p+2:1) putchar('o');
		}
		F(i,1,p-d)
		{
			F(j,1,t) putchar('x');
			if(i != p-d) 
			{
				F(j,1,i == 1 && !d?a-p+2:1) putchar('o');
			}
		}
	}
	return 0;
}
