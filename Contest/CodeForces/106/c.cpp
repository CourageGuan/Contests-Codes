#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=a;i<=b;++i)
#define R(i,n) for(int i=0;i<n;++i)
#define mp make_pair

const int maxn = 1e5 + 10;
int n;
pair<int,int> a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	F(i,1,n)
	{
		int t;
		scanf("%d",&t);
		a[i] = mp(t,i);
	}
	sort(a+1,a+n+1,greater<pair<int,int> >());
	printf("%d\n",(n+1)/2);
	for(int i=2;i<=n;i+=2)
	{
		printf("%d ",a[i].second);
	}
	if(n&1) printf("%d\n",a[n].second);
	else puts("");
	printf("%d\n",n/2);
	for(int i=1;i<=n-(n&1);i+=2)
	{
		printf("%d ",a[i].second);
	}
	puts("");
	return 0;
}
