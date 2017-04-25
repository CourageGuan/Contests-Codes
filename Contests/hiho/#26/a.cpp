#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define f(i,a,b) for(int i=(a);i<=(b);++i)

const double p = 2/(1+sqrt(5));
int n,m;
vector<int> ans;

bool gao(int a,int b)
{
	if(a == 0 && b == 1) return 0;
	if(a == 1 && b == 0) return 1;
	if(b > a)
	{
		ans.push_back(1);
		return gao(a,b-a);
	}
	else
	{
		ans.push_back(0);
		return gao(a-b,b);
	}
}

void solve()
{
	int T,t;
	scanf("%d",&T);
	f(z,1,T)
	{
		scanf("%d",&n);
		m = int(n*p);
		do{
			while(__gcd(n,m) != 1) ++m;
			ans.clear();
			t = gao(n,m);
			++m;
		}while(ans.size() > 60);
		f(i,1,ans.size()) printf("%d",ans[i-1]^t);
		puts("");
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	solve();	
	return 0;
}
