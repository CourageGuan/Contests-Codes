#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define pb push_back

const int maxn = 5e4 + 10;

struct Q{
	int x,y,z;
	int ty,id;
};

vector<Q> op,op1,op2;
vector<int> allZ;
bool isA[maxn];
int bit[2*maxn];
int ans[maxn];

bool cmp1(const Q& a,const Q& b)
{
	if(a.x == b.x) return a.id < b.id;
	return a.x < b.x;
}

bool cmp2(const Q& a,const Q& b)
{
	if(a.y == b.y) return a.id < b.id;
	return a.y < b.y;
}

void add(int x,int v)
{
	for(;x < 2*maxn;x += x&-x) bit[x] += v;
}

int query(int x)
{
	int res = 0;
	for(; x; x -= x&-x) res += bit[x];
	return res;
}

void count()
{
	R(i,op2.size())
		if(!op2[i].ty) add(op2[i].z,1);
		else ans[op2[i].id] += query(op2[i].z)*op2[i].ty;
	R(i,op2.size()) if(!op2[i].ty) add(op2[i].z,-1);
}

void CDQ1(int L,int R)
{
	if(L >= R) return;
	int m = (L+R) >> 1;
	CDQ1(L,m);
	op2.clear();
	F(i,L,m) if(!op1[i].ty) op2.push_back(op1[i]);
	F(i,m+1,R) if(op1[i].ty) op2.push_back(op1[i]);
	sort(op2.begin(),op2.end(),cmp2);
	count();
	CDQ1(m+1,R);
}

void CDQ(int L,int R)
{
	if(L >= R) return;
	int m = (L+R) >> 1;
	CDQ(L,m);
	op1.clear();
	F(i,L,m) if(!op[i].ty) op1.push_back(op[i]);
	F(i,m+1,R) if(op[i].ty) op1.push_back(op[i]);
	sort(op1.begin(),op1.end(),cmp1);
	CDQ1(0,op1.size() - 1);
	CDQ(m+1,R);
}

void init()
{
	fill(ans,0);
	fill(isA,0);
	fill(bit,0);
	allZ.clear();
	op.clear();
}



int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		int n;
		scanf("%d",&n);
		R(i,n)
		{
			int ty,x[2],y[2],z[2];
			scanf("%d %d %d %d",&ty,x,y,z);
			if(ty == 1)
			{
				op.pb((Q){x[0],y[0],z[0],0,i});
				allZ.pb(z[0]);
			}
			else
			{
				scanf("%d %d %d",x+1,y+1,z+1);
				isA[i] = 1;
				op.pb((Q){x[0]-1,y[0]-1,z[0]-1,-1,i});
				op.pb((Q){x[0]-1,y[0]-1,z[1],1,i});
				op.pb((Q){x[0]-1,y[1],z[0]-1,1,i});
				op.pb((Q){x[0]-1,y[1],z[1],-1,i});
				op.pb((Q){x[1],y[0]-1,z[0]-1,1,i});
				op.pb((Q){x[1],y[0]-1,z[1],-1,i});
				op.pb((Q){x[1],y[1],z[0]-1,-1,i});
				op.pb((Q){x[1],y[1],z[1],1,i});

				allZ.pb(z[0]-1);
				allZ.pb(z[1]);
			}
		}
		sort(allZ.begin(),allZ.end());
		int qn = unique(allZ.begin(),allZ.end()) - allZ.begin();
		R(i,op.size()) op[i].z = lower_bound(allZ.begin(),allZ.end(),op[i].z) - allZ.begin() + 1;
		CDQ(0,op.size()-1);
		R(i,n) if(isA[i]) printf("%d\n",ans[i]);
	}
	return 0;
}
