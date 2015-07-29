#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("test.txt","r",stdin);
	int T,n,m,p,q;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&n,&m,&p,&q);
		double pn = p,pm = (double)q/m;
		int ans;
		if(n<=m) ans = min(q,p*n);
		else if(pm>pn)
		{
			ans = p*n;
		}
		else
		{
			ans = min((n/m)*q+p*(n%m),(n/m + (n%m>0) )*q);
		}
		printf("%d\n",ans);
	}
	return 0;
}
