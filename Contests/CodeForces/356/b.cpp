#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 110;
int t[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int a,n;
	scanf("%d %d",&n,&a);
	for(int i=0;i<n;++i) scanf("%d",t+i);
	int l = a - 1,r = a - 1,res = 0;
	for(;l >= 0 || r < n;--l,++r)
	{
		if(((l >= 0 && t[l]) || l < 0) && ((r < n && t[r]) || r >= n))
		{
			if(l >= 0 && r < n) res += 2;
			else res++;
		}
	}
	if(t[a-1]) --res;
	printf("%d\n",res);
	return 0;
}
