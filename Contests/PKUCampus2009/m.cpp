#include<cstdio>
#include<cstring>
using namespace std;
typedef double DB;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define _cnt(x) __builtin_popcount(x)

int next(int x)
{
	int l = x & -x, y = x + l;
	return y | (((x^y) / l) >> 2);
}

const int maxn = 22;
int ra,rb,ca,cb;
char pa[maxn][maxn],pb[maxn][maxn];
int a[maxn],b[maxn];

bool solve()
{
	int msk;
	for(int i=0;i<rb;++i)
	{
		if(i + ra > rb) break;
		if(_cnt(a[0]) > _cnt(b[i])) continue;
		msk = ((1<<ca)-1);
		for(int s= msk;  ;s = next(s))
		{
//			printf("%d %d\n",s,cb);
			int j,k,t;
			for(j = 0 ,k = i;j<ra && k < rb;)
			{
				t = 0;
				for(int l=0;l<cb;++l) if(s&(1<<l)) t = (t<<1) + pb[k][l] - '0';
//				printf("%d %d .. %d %d\n",j,k,a[j],t);
				if(a[j] == t) ++j;
				++k;
			}
	//		puts("");
			if(j >= ra) return 1;
			if(s == ((1<<ca)-1) << (cb-ca)) break;
		}
	//	puts("");
	}
	return 0;
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&ra,&ca) == 2)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		F(i,0,ra-1)
		{
		   	scanf("%s",pa[i]);
			F(j,0,ca-1) a[i] = (a[i]<<1) + pa[i][j] - '0';
		}
		scanf("%d %d",&rb,&cb);
		F(i,0,rb-1)
		{
		   	scanf("%s",pb[i]);
			F(j,0,cb-1) b[i] = (b[i]<<1) + pb[i][j] - '0';
		}
		puts(solve()?"Yes":"No");
	}
	return 0;
}

