#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
int c[10],n,r,b,y;

string solve()
{
	string res = "";
	int mx = max(r,max(y,b));
	if(mx == r)
	{
		if(r > y+b) return string("IMPOSSIBLE");
		int t = y + b - r;
		for(int i=1;i<=t;++i) 
		{
			res += "RYB";
			--r,--y,--b;
		}
		while(r || y || b)
		{
			if(r && y) 
				res += "RY",--r,--y;
			if(r && b) 
				res += "RB",--r,--b;
		}
		return res;
	}
	if(mx == y)
	{
		if(y > r+b) return string("IMPOSSIBLE");
		int t = r + b - y;
		for(int i=1;i<=t;++i) 
		{
			res += "YRB";
			--r,--y,--b;
		}
		while(r || y || b)
		{
			if(y && r) 
				res += "YR",--y,--r;
			if(y && b) 
				res += "YB",--y,--b;
		}
		return res;
	}
	if(mx == b)
	{
		if(b > r+y) return string("IMPOSSIBLE");
		int t = r + y - b;
		for(int i=1;i<=t;++i) 
		{
			res += "BYR";
			--r,--y,--b;
		}
		while(r || y || b)
		{
			if(b && y) 
				res += "BY",--b,--y;
			if(b && r) 
				res += "BR",--b,--r;
		}
		return res;
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	int T; 
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		printf("Case #%d: ",z);
		scanf("%d",&n);
		for(int i=0;i<6;++i) scanf("%d",c+i);
		r = c[0];
		y = c[2];
		b = c[4];
		//printf("%d %d %d\n",r,y,b);
		string ans = solve();
		puts(ans.c_str());
	}
	return 0;
}
