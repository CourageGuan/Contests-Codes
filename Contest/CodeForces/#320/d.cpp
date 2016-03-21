#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 200010;
const double eps = 1e-7;
int n,k,x;
int a[maxn];
int bit[100],tmp[100];

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d%d%d",&n,&k,&x)==3)	
	{
		memset(bit,0,sizeof bit);
		for(int i=0;i<n;++i) scanf("%d",a+i);
		for(int i=0;i<n;++i)
		{
			int t = a[i],p=0;
			while(t)
			{
				if(t&1) ++bit[p];
				++p;
				t>>=1;
			}
		}
		LL ans = 0;
		for(int i=0;i<32;++i) if(bit[i]) ans |= 1<<i;
		for(int i=0;i<n;++i)
		{
			int t = a[i],p=0;
			LL tt = (LL)t*(LL)(pow(x,k)+eps);
			memcpy(tmp,bit,sizeof bit);
			while(t)
			{
				if(t&1) --tmp[p];
				++p;
				t>>=1;
			}
			p = 0;
			while(tt)
			{
				if(tt&1) ++tmp[p];
				++p;
				tt>>=1;
			}
			LL res = 0;
			for(int i=0;i<64;++i) if(tmp[i]) res |= 1LL<<i;
		//	printf("%d\n",res);
			ans = max(ans,res);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}



