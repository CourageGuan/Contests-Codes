#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 5e4;
LL a[4];
LL o,l,ol,lo;

bool solve()
{
	if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)
	{
		puts("0");
		return 1;
	}
	o = l = -1;
	F(i,2,maxn)
	{
		if(1LL*i*(i-1)/2 == a[0])
			o = i;
		if(1LL*i*(i-1)/2 == a[3])
			l = i;
	}
	if(a[0] == 0 && a[3] == 0)
	{
		if(a[1] + a[2] != 1) return 0;
		else
		{
			puts(a[1]?"01":"10");
			return 1;
		}
	}
	else if(a[0] == 0 && l != -1)
	{
		if(a[1] + a[2] == 0)
		{
			R(i,l) putchar('1');
			puts("");
			return 1;
		}
		if(a[1] + a[2] != l) return 0;
		else
		{
			R(i,a[2]) putchar('1');
			putchar('0');
			R(i,a[1]) putchar('1'); 
			puts("");
			return 1;
		}
	}
	else if(a[3] == 0 && o != -1)
	{
		if(a[1] + a[2] == 0)
		{
			R(i,o) putchar('0');
			puts("");
			return 1;
		}
		if(a[1] + a[2] != o) return 0;
		else
		{
			R(i,a[1]) putchar('0');
			putchar('1');
			R(i,a[2]) putchar('0'); 
			puts("");
			return 1;
		}
	}
	if(o == -1 || l == -1) return 0;
	LL len = o + l,sum = len*(len-1)/2;
	if(len > (int)1e6) return 0;
	if(a[1] + a[2] != sum - a[0] - a[3]) return 0;
	int cnt = 0;
	ol = o*l,lo = 0;
	while(ol-o >= a[1])
	{
		ol -= o;
		cnt ++;
	}
	ol -= a[1];
	R(i,cnt) putchar('1');
	R(i,o - ol) putchar('0');
	if(ol) putchar('1');
	R(i,ol) putchar('0');
	R(i,l - cnt - (ol != 0)) putchar('1');
	puts("");
	return 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	R(i,4) scanf("%lld",a+i);
	if(!solve()) puts("Impossible");
	return 0;
}
