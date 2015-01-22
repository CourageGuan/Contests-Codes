#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
const int inf=0x7fffffff;

int main()
{
	int kase;
	scanf("%d",&kase);
	while(kase--){
		int n,m;
		double sa=0,sb=0;
	   	scanf("%d%d",&n,&m);	
		F(i,1,n-1){
			double a;
			scanf("%lf",&a);
			sa+=a;
		}
		F(i,1,m){
			double b;
			scanf("%lf",&b);
			sb+=b;
		}
		double aveb=sb/(double)m,avea=sa/(double)(n-1); 
		int high=(int)avea+1,low=(int)aveb-1;
		int mn=inf,mx=0;
		if(low>high) swap(low,high);
		F(i,low,high)
			if(((double)i+sa)/((double)n) < avea && ((double)i+sb)/((double)(m+1)) > aveb){
				mn=min(mn,i);
				mx=max(mx,i);
			}
		if(mn>mx) swap(mn,mx);
		printf("%d %d\n",mn,mx);
	}
	return 0;
}



