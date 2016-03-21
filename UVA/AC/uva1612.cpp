/*注意精度问题，简单模拟即可*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const double eps=1e-10;
const int maxn=16384 + 10;

int main()
{
	//freopen("test","r",stdin);
	//freopen("1","w",stdout);
	int n,kase=0;
	while(scanf("%d",&n)==1 && n){
		double sum[maxn],op[maxn][7];
		int list[maxn];
		for(int i=1;i<=n;++i){
			double x,y,z;
			scanf("%lf%lf%lf",&x,&y,&z);
			sum[i]=x+y+z;
			op[i][0]=0;
			op[i][1]=x+y;
			op[i][2]=x+z;
			op[i][3]=y+z;
			op[i][4]=x;
			op[i][5]=y;
			op[i][6]=z;
			sort(op[i],op[i]+7);
		}
		bool flag=true;
		for(int i=0;i<n;++i) scanf("%d",&list[i]);
		//for(int i=0;i<n;++i)
		//	cout<<sum[list[i]]<<endl;
		for(int j=1;j<n;++j){
			int i=list[j],k=list[j-1];
			if(sum[i]>sum[k] || fabs(sum[i]-sum[k])<eps){
				int cnt=6;
				while(1){
					if(sum[i]<sum[k] || (fabs(sum[i]-sum[k])<eps && i>k)) break;
					if(cnt<0) {flag=false;break;}
					sum[i]=op[i][cnt--];
				}
				if(!flag) break;
			}
		}
		if(flag)
			printf("Case %d: %.2lf\n",++kase,sum[list[n-1]]);
		else 
			printf("Case %d: No solution\n",++kase);
		
	}
	return 0;
}


