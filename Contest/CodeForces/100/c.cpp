#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)

const int maxn = 1e5 + 10;
int r[maxn],n,tot;
vector<int> res[3];

struct P{
	int p,cnt;
	P(int p=0,int cnt=0):p(p),cnt(cnt) {}
	bool operator<(const P& rhs) const {
		return cnt < rhs.cnt;
	}
};
priority_queue<P> pq;

int num[maxn],sum[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);	
	R(i,n) scanf("%d",r+i);
	sort(r,r+n);
	int cnt = 1;
	R(i,n)
	{
		if(r[i] != r[i+1])
		{
			pq.push(P(r[i],cnt));
			cnt = 1;
		}
		else ++cnt;
	}
	while(!pq.empty())
	{
		P a,b,c;
		a = pq.top(); pq.pop();
		if(pq.empty()) break;
		b = pq.top(); pq.pop();
		if(pq.empty()) break;
		c = pq.top(); pq.pop();

		if(a.p < b.p) swap(a,b);
		if(b.p < c.p) swap(b,c);
		if(a.p < b.p) swap(a,b);

		res[0].push_back(a.p);
		res[1].push_back(b.p);
		res[2].push_back(c.p);
		
		a.cnt--;
		b.cnt--;
		c.cnt--;

		if(a.cnt) pq.push(a);
		if(b.cnt) pq.push(b);
		if(c.cnt) pq.push(c);
	}
	printf("%d\n",res[0].size());
	R(i,res[0].size())
	{
		R(j,3) printf("%d ",res[j][i]);
		puts("");
	}
	return 0;
}

