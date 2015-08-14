#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int maxn = 510;
char pic[maxn][maxn];
#define mp make_pair
map<pair<pair<int,int>,int>,int> d;

int f(int x1,int y1,int x2,int y2)
{
	if(x1>x2 || y1>y2) return 0;
	if(pic[x1][y1] != pic[x2][y2]) return 0;
	if(x1 == x2 || y1 == y2)
	{
		if(x1==x2)
		{
			if(y2 - y1<=2) return pic[x1][y1] == pic[x2][y2];
		}
		else
		{
			if(x2 - x1<=2) return pic[x1][y1] == pic[x2][y2];
		}
	}
	int &ans = d[mp(mp(x1,y1),x2)];
	if(ans) return ans;
	ans = 0;
	ans = (ans+f(x1+1,y1,x2-1,y2)) % mod;
	ans = (ans+f(x1,y1+1,x2-1,y2)) % mod;
	ans = (ans+f(x1+1,y1,x2,y2-1)) % mod;
	ans = (ans+f(x1,y1+1,x2,y2-1)) % mod;
	return ans%mod;
}


int main()
{
	//freopen("test.txt","r",stdin);
	int m,n;
	while(scanf("%d %d",&n,&m)==2)
	{
		d.clear();
		for(int i=0;i<n;++i)
			scanf("%s",pic[i]);
		printf("%d\n",f(0,0,n-1,m-1));
	}
	return 0;
}

