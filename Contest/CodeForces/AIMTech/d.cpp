#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e6 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int m,n,a,b;
int t[maxn];
LL d[maxn][3];
vector<int> fac;

LL solve(int tt,int B)
{
	fac.clear();
	for(int i=2;i*i<=tt;++i)
	{
		if(tt %i == 0){
			fac.push_back(i);
			if(i*i != tt)fac.push_back(tt/i);
			while(tt%i == 0) tt/=i;
		}
		if(tt == 1) break;
	}
	if(tt > 1) fac.push_back(tt);
	sort(fac.begin(),fac.end());
	LL res = INF;
	for(int i=0;i<fac.size();++i)
	{
		int pr = fac[i];
		memset(d,INF,sizeof d);
		d[1][0] = B;
		for(int j=2;j<=n;++j)
		{
			if(t[j-1]%pr)
			{
				if(t[j-1]%pr == 1 || t[j-1]%pr == pr-1)
				{
					d[j][0] = min(d[j][0],d[j-1][0]+b);
					d[j][2] = min(d[j][2],min(d[j-1][1],d[j-1][2])+b);
				}
				d[j][1] = min(d[j][1],min(d[j-1][0],d[j-1][1])+a);
			}
			else
			{
				d[j][0] = d[j-1][0];
				d[j][1] = min(d[j][1],d[j-1][1] + a);
				d[j][2] = min(d[j-1][2],d[j-1][1]);
			}
		}
		res = min(res,min(d[n][0],min(d[n][1],d[n][2])));
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&a,&b);
	for(int i=0;i<n;++i) scanf("%d",t+i);
	LL ans = INF;
	ans = min(ans,solve(t[0]-1,b));
	ans = min(ans,solve(t[0],0));
	ans = min(ans,solve(t[0]+1,b));
	reverse(t,t+n);
	ans = min(ans,solve(t[0]-1,b));
	ans = min(ans,solve(t[0],0));
	ans = min(ans,solve(t[0]+1,b));
	printf("%lld\n",ans);
	return 0;
}
