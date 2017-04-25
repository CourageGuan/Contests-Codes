#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int maxn = 1010;
int n,m,q,sz;
int v[maxn][maxn],id[maxn][maxn];
int D[maxn*maxn],R[maxn*maxn],val[maxn*maxn];
vector<pair<int,int> > swp[2];

int move(int q,int x,int y)
{
	while(x--)  q = D[q];
	while(y--)  q = R[q];
	return q;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&q);
	F(i,1,n) F(j,1,m) scanf("%d",&v[i][j]);
	sz = 0;
	F(i,0,n+1) F(j,0,m+1)
	{
		id[i][j] = sz;
		val[sz++] = v[i][j];
	}
	F(i,0,n) F(j,0,m)
	{
		if(i) D[id[i-1][j]] = id[i][j];
		if(j) R[id[i][j-1]] = id[i][j];
	}
//	F(i,0,n){ F(j,0,m) printf("%d ",R[id[i][j]]); puts("");}
	while(q--)
	{
		int a,b,c,d,h,w,t1,t2;
		scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&h,&w);

		swp[0].clear();
		swp[1].clear();

		t1 = move(id[0][0],a+h-1,b),t2 = move(id[0][0],c+h-1,d);

		R(i,w)
		{
			swp[0].pb(mp(t1,t2));
			t1 = move(t1,0,1);
			t2 = move(t2,0,1);
		}

		t1 = move(id[0][0],a,b+w-1),t2 = move(id[0][0],c,d+w-1);
		R(i,h)
		{
			swp[1].pb(mp(t1,t2));
			t1 = move(t1,1,0);
			t2 = move(t2,1,0);
		}

		t1 = move(id[0][0],a-1,b),t2 = move(id[0][0],c-1,d);
		R(i,w)
		{
			swp[0].pb(mp(t1,t2));
			t1 = move(t1,0,1);
			t2 = move(t2,0,1);
		}

		t1 = move(id[0][0],a,b-1),t2 = move(id[0][0],c,d-1);
		R(i,h)
		{
			swap(R[t1],R[t2]);
			t1 = move(t1,1,0);
			t2 = move(t2,1,0);
		}
		
		R(i,swp[0].size()) swap(D[swp[0][i].fi],D[swp[0][i].se]);
		R(i,swp[1].size()) swap(R[swp[1][i].fi],R[swp[1][i].se]);
	}
	F(i,1,n) 
	{
		int t = move(id[0][0],i,1);
		F(j,1,m)
		{
			printf("%d ",val[t]);
			t = move(t,0,1);
		}
		puts("");
	}
	return 0;
}
