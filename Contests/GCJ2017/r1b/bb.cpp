#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
int c[10],n;

string get(string a,string b,int s)
{
	string res = a; 
	for(int t = 0;t<s;++t) res += b;
	return res;
}

string solve(int dr,int dy,int db,int lr,int ly,int lb)
{
	if(!lr) ++dr;
	if(!ly) ++dy;
	if(!lb) ++db;
	int r,y,b,tr,ty,tb,flag = 0;
	tr = ty = tb = 0;
	if(lr) tr = 1;
	if(ly) ty = 1;
	if(lb) tb = 1;
	r = dr + tr;
	y = dy + ty;
	b = db + tb;
	if(dr == -1)
	{
		if(y || b) return string("IMPOSSIBLE");
		return get("","GR",lr);
	}
	if(dy == -1)
	{
		if(r || b) return string("IMPOSSIBLE");
		return get("","VY",ly);
	}
	if(db == -1)
	{
		if(r || y) return string("IMPOSSIBLE");
		return get("","OB",lb);
	}
	if(dr < 0 || dy < 0 || db < 0) return string("IMPOSSIBLE");
	string res = "";
	int mx = max(r,max(y,b));
	if(mx == r)
	{
		//printf("%d %d %d\n",r,y,b);
		if(r > y+b) return string("IMPOSSIBLE");
		int t = y + b - r;
		for(int i=1;i<=t;++i) 
		{
			if(tr) res += get("R","GR",lr),--tr;
			else res += "R",--dr;
			if(ty) res += get("Y","VY",ly),--ty;
			else res += "Y",--dy;
			if(tb) res += get("B","OB",lb),--tb;
			else res += "B",--db;
			--r,--b,--y;
		}
		while(r || y || b)
		{
			if(r && y) 
			{
				if(tr) res += get("R","GR",lr),--tr;
				else res += "R",--dr;
				if(ty) res += get("Y","VY",ly),--ty;
				else res += "Y",--dy;
				--r,--y;
			}
			if(r && b) 
			{
				if(tr) res += get("R","GR",lr),--tr;
				else res += "R",--dr;
				if(ty) res += get("Y","VY",ly),--ty;
				else res += "Y",--dy;
				if(tb) res += get("B","OB",lb),--tb;
				else res += "B",--db;
				--r,--b;
			}
		}
	}
	else
	if(mx == y)
	{
		if(y > r+b) return string("IMPOSSIBLE");
		int t = r + b - y;
		for(int i=1;i<=t;++i) 
		{
			if(ty) res += get("Y","VY",ly),--ty;
			else res += "Y",--dy;
			if(tr) res += get("R","GR",lr),--tr;
			else res += "R",--dr;
			if(tb) res += get("B","OB",lb),--tb;
			else res += "B",--db;
			--r,--b,--y;
		}
		while(r || y || b)
		{
			if(y && r) 
			{

				if(ty) res += get("Y","VY",ly),--ty;
				else res += "Y",--dy;
				if(tr) res += get("R","GR",lr),--tr;
				else res += "R",--dr;
				--y,--r;
			}
			if(y && b) 
			{
				if(ty) res += get("Y","VY",ly),--ty;
				else res += "Y",--dy;
				if(tb) res += get("B","OB",lb),--tb;
				else res += "B",--db;
				--y,--b;
			}
		}
	}
	else
	{
		if(b > r+y) return string("IMPOSSIBLE");
		int t = r + y - b;
		for(int i=1;i<=t;++i) 
		{
			if(tb) res += get("B","OB",lb),--tb;
			else res += "B",--db;
			if(ty) res += "YVY",--ty;
			else res += "Y",--dy;
			if(tr) res += get("R","GR",lr),--tr;
			else res += "R",--dr;
			--r,--b,--y;
		}
		while(r || y || b)
		{
			if(b && y) 
			{
				if(tb) res += get("B","OB",lb),--tb;
				else res += "B",--db;
				if(ty) res += "YVY",--ty;
				else res += "Y",--dy;
				--b,--y;
			}

			if(b && r) 
			{
				if(tb) res += get("B","OB",lb),--tb;
				else res += "B",--db;
				if(tr) res += get("R","GR",lr),--tr;
				else res += "R",--dr;
				--b,--r;
			}
		}
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	//freopen("B-large.in","r",stdin);
	//freopen("B.out","w",stdout);
	int T; 
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		printf("Case #%d: ",z);
		scanf("%d",&n);
		for(int i=0;i<6;++i) scanf("%d",c+i);
		int r,y,b,tr,ty,tb;
		r = c[0];
		y = c[2];
		b = c[4];
		tr = c[3];
		ty = c[5];
		tb = c[1];
		string ans = solve(r-tr-1,y-ty-1,b-tb-1,tr,ty,tb);
		puts(ans.c_str());
	}
	return 0;
}
