#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2010;
int n,m,k;
int pa[2],pb[2];
LL sa,sb,cur,ta,a[maxn],b[maxn];

vector<LL> V;

int main()
{
	//freopen("test.txt","r",stdin);
	sa = sb = 0;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%lld",a+i),sa += a[i];
	scanf("%d",&m);
	for(int i=0;i<m;++i) scanf("%lld",b+i),sb += b[i];
	k = 0; cur = abs(sa - sb);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(cur > abs(sa + 2*b[j] - sb - 2*a[i]))
			{
				k = 1;
				cur = abs(sa + 2*b[j] - sb - 2*a[i]);
				pa[0] = i+1,pb[0] = j+1;
			}

//	for(int i=0;i<pn;++i) printf("%d ",V[i]);
	if(n > 1)
	{
		for(int i=0;i<n;++i) 
			for(int j=i+1;j<n;++j)
				V.push_back(2*(a[i]+a[j]));
		sort(V.begin(),V.end());
		int pn = unique(V.begin(),V.end()) - V.begin();

		for(int i=0;i<m;++i)
			for(int j=i+1;j<m;++j)
			{
				LL bb = 2*(b[i] + b[j]),aa;
				//printf("%lld\n",sa - sb + bb);
				vector<LL>::iterator p = lower_bound(V.begin(),V.begin()+pn,sa - sb + bb);
				if(p == V.end()) --p;
				if(p == V.begin()) aa = *p;
				else aa = abs(sa + bb - sb - *p) > abs(sa + bb - sb - *(p-1)) ?*(p-1):*p;
				if(cur > abs(sa + bb - sb - aa))
				{
					k = 2;
					cur = abs(sa + bb - sb - aa);
					pb[0] = i+1;
					pb[1] = j+1;
					ta = aa;
				}
			}
	}
	if(k == 2)
	{
		for(int i=0;i<n;++i) 
			for(int j=i+1;j<n;++j)
				if(a[i] + a[j] == ta/2)
				{
					pa[0] = i+1;
					pa[1] = j+1;
				}
	}
	printf("%lld\n",cur);
	printf("%d\n",k);
	for(int i=0;i<k;++i)
		printf("%d %d\n",pa[i],pb[i]);
	return 0;
}


