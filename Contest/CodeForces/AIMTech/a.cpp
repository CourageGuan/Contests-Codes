#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const double eps = 1e-12;
int d,L,v1,v2;

double solve()
{
	double l=0,r=L-d,res;
	while(r - l > eps)
	{
		double mid = (l+r)/2,mmid = (mid + r)/2;
		double fmid = min(mid/v1,(L-d-mid)/v2);
		double fmmid = min(mmid/v1,(L-d-mmid)/v2);
		if(fmid > fmmid)
		{
			res = fmid;
			r = mmid;
		}
		else
		{
			res = fmmid;
			l = mid;
		}
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d",&d,&L,&v1,&v2);
	printf("%.12lf\n",(double)(L-d)/(v1+v2));
//	printf("%.12f\n",solve());
	return 0;
}
