#include<bits/stdc++.h>
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 222,maxc = 26;
int ch[maxn][maxc],fail[maxn],sum[maxn];
int size = 0;

int idx(char& c)
{
	return c - 'a';
}

void insert(char s[],int v)
{
	int n = strlen(s),u = 0;
	F(i,0,n-1)
	{
		int j = idx(s[i]);
		if(!ch[u][j])
			ch[u][j] = ++size;
		u = ch[u][j];
	}
	sum[u] += v;
}

void getFail()
{
	std::queue<int> q; 
	F(i,0,25) if(ch[0][i]) q.push(ch[0][i]);
	while(q.size())
	{
		int u = q.front(); q.pop();
		F(i,0,25) if(ch[u][i])
		{
			q.push(ch[u][i]);
			fail[ch[u][i]] = ch[fail[u]][i];
			sum[ch[u][i]] += sum[ch[fail[u]][i]];
		}
		else ch[u][i] = ch[fail[u]][i];
	}
}

struct Matrix{
	LL m[maxn][maxn];
	Matrix()
	{
		memset(m,-1,sizeof m);
	}
} A,B;

Matrix operator*(const Matrix &a,const Matrix &b)
{
	Matrix res;
	F(i,0,size) F(j,0,size) F(k,0,size)
		if(a.m[i][k] != -1 && b.m[k][j] != -1)
			res.m[i][j] = std::max(res.m[i][j],a.m[i][k] + b.m[k][j]);

	return res;
}

char s[maxn];
int a[maxn],n;
LL l;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %lld",&n,&l);

	F(i,1,n) scanf("%d",a+i);
	F(i,1,n) scanf("%s",s),insert(s,a[i]);

	getFail();
	
	F(i,0,size) F(j,0,25)
		A.m[i][ch[i][j]] = sum[ch[i][j]];
	B = A;

	--l;
	while(l)
	{
		if(l&1) B = B*A;
		A = A*A;
		l >>= 1;
	}

	LL ans = 0;
	F(i,0,size) ans = std::max(ans,B.m[0][i]);
	printf("%lld\n",ans);
	return 0;
}
