/*n个以(x,y)为圆心以d为半径的圆与x轴交点构成线段
 * 即最少的点覆盖所有线段问题：对所有线段按区间尾部排序，每次取尾部
 * 若不能覆盖，则更新当前点*/
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

const double eps=1e-10;
const int maxn=100000 + 10;

struct indual{
	double a,b;
	bool operator <(const indual &r) const {
		if(fabs(b-r.b)<eps) return a>r.a;
		else return b<r.b;
	}
} ls[maxn];


int main()
{
	//freopen("test","r",stdin);
	double len,d; 
	int n;
	while(scanf("%lf%lf%d",&len,&d,&n)==3){
		for(int i=0;i<n;++i){
			double x,y;
			scanf("%lf%lf",&x,&y);
			x=fabs(x);y=fabs(y);
			ls[i].a=max(0.0,x-sqrt(d*d-y*y));
			ls[i].b=min(len,x+sqrt(d*d-y*y));
		}
		sort(ls,ls+n);
		//for(int i=0;i<n;++i) cout<<ls[i].a<<" "<<ls[i].b<<endl;
		int ans=1;double cur=ls[0].b;
		for(int i=1;i<n;++i)
			if((ls[i].a<cur || fabs(ls[i].a-cur)<eps) && (cur<ls[i].b || fabs(ls[i].b-cur)<eps)){}
			else{cur=ls[i].b;ans++;}
		printf("%d\n",ans);
	}
	return 0;
}

