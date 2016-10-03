#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int n,k;
LL x;
LL a[maxn],ans[maxn];

struct P {
	LL v;
	int id,op;
	P(LL v,int id,int op):v(v),id(id),op(op) {};
	P() {};
	bool operator<(const P& rhs) const
	{
		return v > rhs.v;
	}
};

priority_queue<P> q;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %lld",&n,&k,&x);
	int op = 1,cur = INF,pos;
	F(i,1,n)
	{
	   	scanf("%lld",a+i);
//		printf("%lld ",a[i]);
		if(a[i] < 0) op = -op;
		if(abs(a[i]) < cur)
		{
			cur = abs(a[i]);
			pos = i;
		}
	}

	if(op >= 0)
	{
		if(cur == 0)
		{
			a[pos] -= x;
			k--;
		}
		else
		{
			cur ++;
			LL t = cur/x + (cur%x != 0);
			if(t > k) t = k;
			if(a[pos] < 0)
				a[pos] += t*x;
			else
				a[pos] -= t*x;
			k -= t;
		}
	}

	F(i,1,n)
	{
//		printf("%d ",a[i]);
		q.push(P(abs(a[i]),i,a[i]>=0?1:-1));
	}
//	puts("");

	while(k--)
	{
		P p = q.top();
		q.pop();
		p.v += x;
		q.push(p);
	}

	while(q.size()) ans[q.top().id] = q.top().v*(q.top().op),q.pop();
	F(i,1,n) printf("%lld ",ans[i]);
	return 0;
}
