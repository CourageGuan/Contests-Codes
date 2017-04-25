#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const double eps = 1e-11;
const int maxn = 200010;
double a[maxn],mn,mx;
int n;

double cal(double x)
{
	double res = 0;
	double cur = 0;
	for(int i=0;i<n;++i)
	{
		cur = max(0.0,cur+a[i]+x);
		res = max(cur,res);
	}
	cur = 0;
	for(int i=0;i<n;++i)
	{
		cur = max(0.0,cur-(a[i]+x));
		res = max(cur,res);
	}
	return res;
}

double solve()
{
	double high = -mn,low = -mx;
	int cnt = 0;
//	for(int i=0;i<85;++i)
	while(high-low>eps)
	{
		double mid = (high+low)/2;
		double midmid = (mid+high)/2;
		double cmid = cal(mid),cmidmid = cal(midmid);
		if(cmid > cmidmid)
			low = mid;
		else
			high = midmid;
	}
//	printf("%d\n",cnt);	
	return cal((low+high)/2);
}


int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n)==1)
	{
		mx = -10001;
		mn = 10000;
		for(int i=0;i<n;++i)
		{
		   	scanf("%lf",a+i); 
			mx = max(a[i],mx);
			mn = min(a[i],mn);
		}
		printf("%.12lf\n",solve());
	}
	return 0;
}

