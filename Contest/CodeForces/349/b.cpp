#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 +10;
int n;
int l[maxn],sum;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",l+i);
	sort(l,l+n);
	for(int i=0;i<n-1;++i) sum += l[i];
	printf("%d\n",l[n-1] - sum + 1);
	return 0;
}
