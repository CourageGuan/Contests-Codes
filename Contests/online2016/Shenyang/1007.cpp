#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

LL d[20][3][20];
int dig[20];

LL dfs(int x,int pre,int len,int li)
{
	if(x < 0)
	   	return (pre==0 && (len&1)) || (pre == 1 && !(len&1));
	LL &ans = d[x][pre][len];
	if(!li && ans != -1) return ans;
	LL res = 0;
	int lst = li?dig[x]:9;
	F(i,0,lst)
	{
		if(pre == 2)
		{
			res += dfs(x-1,i==0?2:i&1,1,li && (i == lst));
		}
		else if((i&1) == pre)
		{
			res += dfs(x-1,i&1,len+1,li && (i == lst));
		}
		else
		{
			if((pre==0 && (len&1)) || (pre == 1 && !(len&1)))
				res += dfs(x-1,i&1,1,li && (i == lst));
		}
	}
	if(!li) ans = res;
	return res;
}

LL cal(LL n)
{
	int len = 0;
	while(n)
	{
		dig[len++] = n%10;
		n /= 10;
	}
	return dfs(len-1,2,0,1);
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;	
	scanf("%d",&T);
	memset(d,-1,sizeof d);
	F(z,1,T)
	{
		LL L,R;
		scanf("%lld %lld",&L,&R);
		LL res = cal(R) - cal(L-1);
		printf("Case #%d: %lld\n",z,res);
	}
	return 0;
}
