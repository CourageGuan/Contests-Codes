#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 510;
const int INF = 0x3f3f3f3f;
int d[maxn][maxn],a[maxn];


int dp(int L,int R)
{
	if(L == R) return 1;
	if(L+1==R) return 2-(a[L] == a[R]);
	int &ans = d[L][R];
	if(ans != -1) return ans;
	ans = INF;
	if(a[L] == a[R]) ans = dp(L+1,R-1);
	for(int i=L;i<R;++i)
	{
		ans = min(ans,dp(L,i)+dp(i+1,R));
	}
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	memset(d,-1,sizeof d);
	printf("%d\n",dp(0,n-1));
	return 0;
}
