#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int s[maxn];
int n,k;

int solve()
{
	int ans = s[n-1];
	if(k >= n) return ans;
	else
	{
		int t = 2*(n-k); 
		for(int i=0;i<t/2;++i)
		{
			ans = max(ans,s[i]+s[t-i-1]);
		}

	} 
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i) scanf("%d",s+i);
	printf("%d\n",solve());
	return 0;
}
