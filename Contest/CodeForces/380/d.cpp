#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
int n,a,b,k;
char s[maxn];
vector<int> V;

void solve()
{
	scanf("%d %d %d %d",&n,&a,&b,&k);
	scanf("%s",s+1);
	V.push_back(0);
	F(i,1,n)
		if(s[i] == '1') V.push_back(i);
	V.push_back(n+1);
	int cnt = 0;
	for(int i=1;i<V.size();++i)
	{
		int len = V[i] - V[i-1] - 1;
		if(len >= b)
		{
			cnt += len/b;
		}
	}
	if(cnt < a) puts("0");
	else
	{
		printf("%d\n",cnt - a + 1);
		cnt -= a - 1;
		for(int i=1;i<V.size();++i)
		{
			int len = V[i] - V[i-1] - 1;
			if(len >= b)
			{
				int t = V[i-1] + b;
				while(t < V[i])
				{
					printf("%d ",t);
					--cnt;
					t += b;
					if(!cnt) break;
				}
				if(!cnt) break;
			}
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}
