#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof a)

const int maxn = 1e5 + 10;
int n,m,q;
vector<int> T[maxn];
int a[maxn],b[maxn],f[maxn],s[maxn];
int l[maxn],r[maxn],x[maxn],y[maxn],z[maxn];


int find(int x)
{
	return x == f[x]?x:f[x] = find(f[x]);
}

void merge(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return ;
	f[x] = y;
	s[y] += s[x];
}


int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m;
	R(i,m) scanf("%d %d",a+i,b+i);
	cin >> q;
	R(i,q) scanf("%d %d %d",x+i,y+i,z+i),l[i] = 0,r[i] = m-1;
	R(i,20)
	{
		R(i,m) T[i].clear();
		R(i,q) if(l[i] != r[i]) T[l[i]+r[i]>>1].push_back(i);
		F(i,1,n) f[i] = i,s[i] = 1;

		R(i,m)
		{
			merge(a[i],b[i]);
			R(j,T[i].size())
			{
				int k = T[i][j],t ;
				if(find(x[k]) == find(y[k])) t = s[find(x[k])];
				else t = s[find(x[k])] + s[find(y[k])];
				if(t < z[k]) l[k] = i+1;
				else r[k] = i;
			}
		}
	}
	R(i,q) printf("%d\n",l[i]+1);
	return 0;
}
