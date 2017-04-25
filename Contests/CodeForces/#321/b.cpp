#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 1e5 + 10;
struct Node 
{
	int a,b;
	Node(int a=0,int b=0):a(a),b(b) {}
	bool operator<(const Node& rhs) const
	{
		return a<rhs.a;
	}
} a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,d;
	while(scanf("%d",&n)==1)
	{
		scanf("%d",&d);
		for(int i=0;i<n;++i)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			a[i] = Node(x,y);
		}
		sort(a,a+n);
		LL res = a[0].b , cur = res;
		queue<int> Q;
		Q.push(0);
		for(int i=1;i<n;++i)
		{
			while(!Q.empty() && a[i].a - a[Q.front()].a >= d)
			{
				cur -= a[Q.front()].b;
			   	Q.pop();
			}
			Q.push(i);
			cur += a[i].b;
			res = max(res,cur);
		}
		printf("%I64d\n",res);
	}
	return 0;
}
