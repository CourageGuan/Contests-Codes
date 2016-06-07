#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL; 

const int maxn = 8e3 + 10;
int a[maxn],b[maxn],l[2*maxn],r[2*maxn],cnt[maxn];
int n;
vector<int> ans;

int main()
{
	//freopen("test.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		ans.clear();
		for(int i=0;i<n;++i) scanf("%d",a+i),b[i]=a[i];
		sort(b,b+n);
		for(int i=0;i<n;++i) a[i] = lower_bound(b,b+n,a[i]) - b;
		for(int i=0;i<n;++i)
		{
			memset(cnt,0,sizeof cnt);
			memset(l,0,sizeof l);
			memset(r,0,sizeof r);
			for(int j=0;j<n;++j)
			{
				if(a[j] > a[i]) ++cnt[j];
				else if(a[j] < a[i]) --cnt[j];
			}
			int sum = 0;
			l[n] = r[n] = 1;
			for(int j=i+1;j<n;++j)
			{
				sum += cnt[j];
				r[sum+n]++;
			}
			sum = 0;
			for(int j=i-1;j>=0;--j)
			{
				sum += cnt[j];
				l[sum+n]++;
			}		
			int res = 0;
			for(int j=1;j<2*n;++j)
				res += l[j]*r[2*n-j];
//			printf("%d %d %d\n",res,l[n],r[n]);
			ans.push_back(res);
		}
		for(int i=0;i<ans.size();++i) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
	}
	return 0;
}
