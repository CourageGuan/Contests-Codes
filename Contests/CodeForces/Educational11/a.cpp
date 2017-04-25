#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> res;

int main()
{
//	freopen("test.txt"."r",stdin);
	int n,a;
	scanf("%d",&n);
	scanf("%d",&a);
	res.push_back(a);
	for(int i=1;i<n;++i)
	{
		scanf("%d",&a);
		if(__gcd(a,res.back()) != 1) res.push_back(1);
		res.push_back(a);
	}
	printf("%d\n",res.size() - n);
	for(int i=0;i<res.size();++i) printf("%d ",res[i]);
	return 0;
}
