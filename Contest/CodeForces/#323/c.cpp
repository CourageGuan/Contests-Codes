#include<bits/stdc++.h>
using namespace std;

const int maxn = 501;
const double eps = 1e-10;

int a[maxn*maxn],b[maxn*maxn],cnt[maxn*maxn];
map<int,int> decc;

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

int main()
{
	//freopen("ans.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n*n;++i) scanf("%d",a+i);
	sort(a,a+n*n,greater<int>());
	int pn = 0,ct = 1;
	a[n*n] = -1;
	for(int i=1;i<=n*n;++i)
	{
		if(a[i]!=a[i-1])
		{
			b[pn] = a[i-1];
			cnt[pn++] = ct;
			ct = 1;
		}
		else ++ct;	
	}
	decc.clear();	
	vector<int> ans;

	for(int i=0;i<pn;++i)
	{
		int cur = 0,de = decc[b[i]];
		bool flag = false;
		for(int j=i-1;j>=0;--j)
		{
			if(b[j]%b[i] == 0) cur += ans[j];
		}
		//printf("%d %d %d\n",b[i],cur,cnt[i]-de);
		int j = 1;
		while(j*j + 2*cur*j <= cnt[i] - de)
		{
			if( ((j+2*cur)*j) == (cnt[i] - de))
			{
				ans.push_back(j);
				flag = true;
				break;
			}
			++j;
		}
		if(!flag) ans.push_back(0);
		for(int j=i-1;j>=0;--j)
		{
			decc[gcd(b[i],b[j])] += ans[i]*ans[j]*2;
		}
	}
	ct = 0;
	for(int i=0;i<ans.size();++i)
	{
		for(int j=0;j<ans[i];++j)
		{
			printf("%d%c",b[i],++ct == n?'\n':' ');
		}
	}
//	printf("%d\n",ct);
	return 0;
}

