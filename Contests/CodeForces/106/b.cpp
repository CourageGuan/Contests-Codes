#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=a;i<=b;++i)
#define R(i,n) for(int i=0;i<n;++i)

int val[255]; 
string s;

void init()
{
	R(i,10) val['0'+i] = i;
	F(i,'A','Z') val[i] = i - 'A' + 10;
}


bool check(string h,string m)
{
	int i = 0;
	while(i<h.size() && h[i]=='0') ++i;
	if(!(i == h.size() || i == h.size()-1 && h[i] <= 'N')) return 0;
	i = 0;
	while(i<m.size() && m[i]=='0') ++i;
	return i >= m.size() - 1;
}

bool ok(string h,string m)
{
	bool flag = 0;
	int t = 1;
	while(t++)
	{
		bool op = 0;
		LL a = 0,b = 0;
		R(i,h.size())
		{
			if(val[h[i]] >= t)
			{
				op = 1;
				break;
			}
			a = a*t + val[h[i]];
		}
		if(op) continue;
		R(i,m.size())
		{
			if(val[m[i]] >= t)
			{
				op = 1;
				break;
			}
			b = b*t + val[m[i]];
		}
		if(op) continue;
		//printf("%lld %lld\n",a,b);
		if(a < 24 && b < 60)
		{
			printf("%d ",t);
			flag = 1;
		}
		else break;
	}
	return flag;
}

int main()
{
	//freopen("test.txt","r",stdin);
	init();
	cin >> s;
	string h = s.substr(0,s.find(":")),m = s.substr(s.find(":")+1);
	if(check(h,m))
		puts("-1");
	else
	{
		if(!ok(h,m))
			putchar('0');
		puts("");
	}
	return 0;
}
