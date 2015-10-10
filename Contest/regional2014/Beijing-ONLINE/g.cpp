#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;
int p[210];


int main()
{
	//freopen("test.txt","r",stdin);
	int T,n,x;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		memset(p,0,sizeof p);
		for(int i=0;i<n;++i)
		{
		   	scanf("%d",&x);
			++p[abs(x-100)];
		}
		int mx = 0 ,cnt = 0 ;
		for(int i=0;i<=100;++i)
		{	
			mx = max(p[i],mx);
			if(p[i]) ++cnt;
		}
		vector<int> ans;
		for(int i=100;i>=0;--i)
	   	{
			if(p[i]==mx)
			{
				ans.push_back(10000 - i*i);
			}
		}
		printf("Case #%d:\n",z);
		if(ans.size() == cnt && cnt!=1) puts("Bad Mushroom");
		else
		{ 
			for(int i=0;i<ans.size();++i) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
		}
	}
	return 0;
}

