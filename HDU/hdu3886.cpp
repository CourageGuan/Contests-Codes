//数位dp
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

using namespace std;
typedef int LL;

const int mod = 100000000;
const int maxn = 110;
char s[maxn];
int dig[maxn],lenn,lens;
LL d[maxn][maxn][10];

inline bool check(int x,int y,char c)
{
	if(c=='-') return x == y;
	if(c=='/') return x < y;
	if(c=='\\') return x > y;
	return false;
}


LL dfs(int x,int p,int pre,int fi,int limit)
{
	if(x==lenn) return p == lens;
	LL &ans = d[lenn-x][p][pre];
	if(!limit && ans!=-1) return ans;
	int last = limit?dig[x]:9;
	LL res = 0;
	for(int i=0;i<=last;++i)
	{
		if(!fi)
		{
			res = (res + dfs(x+1,p,i,i!=0,limit && i==last)) % mod;
		}
		else if( p<lens && check(pre,i,s[p]) )
		{
			res = (res + dfs(x+1,p+1,i,fi,limit && i==last)) % mod;
		}
		else if(p>0 && check(pre,i,s[p-1]))
		{
			res = (res + dfs(x+1,p,i,fi,limit && i==last)) % mod;
		}
	}
	if(!limit) ans = res;
	return res;
}

LL solve(int a[],int len)
{
	lenn = len;
	memcpy(dig,a,sizeof dig);
//	for(int i=0;i<len;++i) printf("%d",dig[i]);
//	puts("");
	LL res = dfs(0,0,0,0,1);
	return res%mod;
}


inline int getnum(int a[])
{
	int len = 0;
	bool flag = false;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c))
	{
		if(c!='0') flag = true;
		if(flag) a[len++] = c - '0';
	   	c = getchar();
	}
	if(len==0)
	{
		a[0] = 0;
	   	return 1;
	}
	return len;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int a[maxn],b[maxn];
	while(scanf("%s",s)==1)
	{
		lens = strlen(s);
		int lena = getnum(a) , lenb = getnum(b);
		memset(d,-1,sizeof d);
		if(!a[0])
		{
			printf("%08d\n",solve(b,lenb));
			continue;
		}
		int i = lena - 1;
		--a[i];
		while(i>=0 && a[i]<0)
		{
			a[i]+=10;
			--a[--i];
		}
		if(a[0]==0)
		{
			--lena;
		   	for(int i=0;i<lena;++i) a[i] = a[i+1];
		}
		printf("%08d\n",(solve(b,lenb) - solve(a,lena) + mod) % mod);
	}
	return 0;
}

