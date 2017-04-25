#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 110;
int a[maxn],n;
vector<int> one;

int main()
{
	freopen("test.txt","r",stdin);
	bool flag = false;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",a+i);
		if(a[i])
		{
			flag = true;
			one.push_back(i);
		}
	}
	LL res = 1;
	for(int i=1;i<one.size();++i)
	{
		res *= (one[i]-one[i-1]) ;
	}
	if(!flag) puts("0");
	else printf("%lld\n",res);
	return 0;
}
