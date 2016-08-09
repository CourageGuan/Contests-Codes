#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
const int INF = 0x3f3f3f3f;

const int maxn = 3e5 + 10;

int n,q;
vector<int> G[maxn];
int cur,sum,mxt;

int B[maxn];

inline int lowbit(int x){
	return x&(-x);
}

void add(int x,int d){
	for(int i=x;i<maxn;i+=lowbit(i)){
		B[i]+=d;
	}
}

int query(int x){ 
	int res=0;
	for(int i=x;i>0;i-=lowbit(i)){
		res+=B[i];
	}
	return res;
}



int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >>	q;
	cur = sum = 0;
	R(i,q)
	{
		int op,t;
		scanf("%d %d",&op,&t);
		if(op == 1)
		{
			++cur;
			++sum;
			add(sum,1);
			G[t].push_back(sum);
			printf("%d\n",cur);
		}
		else if(op == 2)
		{
			R(j,G[t].size())
			{
				add(G[t][j],-1);
				if(G[t][j] <= mxt) continue;
				--cur;
			}
			G[t].clear();
			printf("%d\n",cur);
		}
		else if(op == 3)
		{
			if(t <= mxt)
			{
				printf("%d\n",cur);
				continue;
			}
//			printf("%d %d %d %d\n",t,mxt,query(t),query(mxt));
			cur -= query(t) - query(mxt);
			mxt = t;
			printf("%d\n",cur);
		}
		assert(cur >= 0);
	}
	return 0;
}
