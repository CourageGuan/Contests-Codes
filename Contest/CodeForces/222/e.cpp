#include<bits/stdc++.h>
using namespace std;

#define R(i,n) for(int i=0;i<(n);++i)

const int maxn = 110;
const int INF = 0x3f3f3f3f;
int d[1<<20],s[maxn];
char op[maxn][2],team[maxn];
int n,m;

int dp(int msk,int k)
{
	if(d[msk] != -1) return d[msk];
	if(k >= m) return 0;
	int &ans = d[msk];
	ans = 0;
	while(k < m)
	{
		int tmp,i;
		if(op[k][0] == 'p')
		{
			for(i=0;i<n;++i) if(!(msk&(1<<i))) break;
			msk |= 1<<i;
			ans += (team[k] == 1)?s[i]:-s[i];
		}
		else
		{
			tmp = team[k]==1?-INF:INF;
			for(i=0;i<n;++i) if(!(msk&(1<<i))) 
			{
				int cur = dp(msk|(1<<i),k+1);
				tmp = (team[k] == 1)?max(tmp,cur):min(tmp,cur);
			}
			ans += tmp;
			break;
		}
		++k;
	}
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	R(i,n)
		scanf("%d",s+i);
	sort(s,s+n,greater<int>());
	scanf("%d",&m);
	R(i,m)
	   	scanf("%s %d",op[i],team+i);
	memset(d,-1,sizeof d);
	n = min(n,20);
	printf("%d\n",dp(0,0));
	return 0;
}
