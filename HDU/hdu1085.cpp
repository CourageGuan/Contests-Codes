#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 8010;
int a,b,c;

int cnt[maxn],C[maxn];


int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%d %d %d",&a,&b,&c) == 3 && a+b+c)
	{
		int mx = a + b*2 + c*5;
		fill(cnt,0);
		fill(C,0);
		R(i,a+1) C[i] = 1;
		R(i,b+1)
		{
			R(k,a+1)
			{
				if(2*i + k > mx) break;
				cnt[2*i+k] += C[k];
			}
		}
		memcpy(C,cnt,sizeof(C));
		fill(cnt,0);
		R(i,c+1)
		{
			R(k,a+2*b+1)
			{
				if(5*i + k > mx) break;
				cnt[5*i+k] += C[k];
			}
		}
		int res = 0;
		R(i,maxn) if(cnt[i] == 0)
		{
//			puts("ok");
			res = i;
			break;
		}
		printf("%d\n",res);
	}
	return 0;
}
