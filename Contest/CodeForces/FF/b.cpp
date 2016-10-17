#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef double DB;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1010;
const int maxk = 1e6 + 10;
int n,m,k,p;
int a[maxn][maxn];
LL ans[maxk];
priority_queue<LL> q;

void solve()
{
	F(i,1,n) F(j,1,m)
		scanf("%d",&a[i][j]);

	F(i,1,n)
	{
		LL sum = 0;
		F(j,1,m) sum += a[i][j];
		q.push(sum);
	}

	LL res = 0;
	F(i,1,k)
	{
		LL t = q.top(); q.pop();
		res += t;
		t -= m*p;
		q.push(t);
		ans[i] = res;
	}

	while(q.size()) q.pop();

	F(j,1,m)
	{
		LL sum = 0;
		F(i,1,n) sum += a[i][j];
		q.push(sum);
	}

	LL an = ans[k];
	res = 0;
	F(i,1,k)
	{
		LL t = q.top(); q.pop();
		res += t;
		t -= n*p;
		q.push(t);
		an = max(an,ans[k-i]+res - 1LL*i*(k-i)*p);
	}
	printf("%lld\n",an);
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d %d %d",&n,&m,&k,&p) == 4)
	{
		solve();
	}
	return 0;
}
