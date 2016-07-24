#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;
#define R(i,n) for(int i=0;i<(n);++i)
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fill(a,b) memset(a,b,sizeof (a));
#define mp make_pair

const int maxn = 3e5 + 10;
int p[maxn],pos[maxn];
int vis[maxn];
int L[maxn],R[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	cin >> n >> m;
	F(i,1,n) scanf("%d",p+i),pos[p[i]] = i;
	R(i,m)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(pos[a] > pos[b]) swap(a,b);
		a = pos[a];
		b = pos[b];
		L[a] = 1;
		R[b] = max(R[b],a);
	}
	LL res = 0;
	int j = 1;
	F(i,1,n)
	{
		vis[i-1] = 0;
		while(j <= n && !vis[R[j]])
		{
			if(L[j]) vis[j] = 1;
			++j;
		}
		if(j > n) break;
		res += n - j + 1;
	}
	cout << 1LL*n*(n+1)/2 - res << '\n';
	return 0;
}
