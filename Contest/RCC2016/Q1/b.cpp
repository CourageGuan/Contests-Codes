#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
typedef long long LL;
int n,h;
int a[maxn],on[maxn];

int main()
{
	freopen("02","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&h);
		for(int i=0;i<n;++i) scanf("%d",a+i);
		int r,res = 0,len = 0;
		for(int i=0;i<n;++i) scanf("%d",on+i);
		if(!on[0]) ++res,on[0] = 1;
		if(!on[n-1]) ++res,on[n-1] = 1;
		for(r=0;r<n;++r)
		{
			if(on[r])
			{ 
				len = 0;
				continue;
			}
			len += a[r];
			if(len >= h && !on[r]) ++res,len = 0;
		}
		printf("%d\n",res);
	}
	return 0;
}

