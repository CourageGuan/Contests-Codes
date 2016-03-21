//转化为区间选点过最多区间问题
//其中转化过程,以及选点的维护过程值得借鉴
#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back
const int INF=0x3f3f3f3f;
struct Point{
	int p;
	int type;	// Right 0  Left 1
	Point(int p,int t): p(p),type(t) {}
	bool operator<(const Point& rhs) const {
		return p<rhs.p || (p==rhs.p && type<rhs.type);
	}
};
vector<Point> q;

// 0<x+ta<w
// 0<y+tb<h	   共用一个函数
void cal(int x,int a,int w,int& l,int& r)
{
	if(a==0){
		if(x<=0 || x>=w) r=l-1;	//无解
	}else if(a>0){				   
		l=max(l,-x*2520/a);		//lcm(1,2,...10)=2520;
		r=min(r,(w-x)*2520/a);
	}
	else{
		l=max(l,(w-x)*2520/a);
		r=min(r,-x*2520/a);
	}
}

int main()
{
	//freopen("test","r",stdin);
	int T,n,w,h;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&w,&h);
		scanf("%d",&n);
		q.clear();
		int x,y,a,b;
		for(int i=0;i<n;++i){
			scanf("%d %d %d %d",&x,&y,&a,&b);
			int l=0,r=INF;
			cal(x,a,w,l,r);
			cal(y,b,h,l,r);
			if(r>l){
				q.pb(Point(l,1));
				q.pb(Point(r,0));
			}
		}
		sort(q.begin(),q.end());
		int cnt=0,ans=0;
		for(int i=0;i<q.size();++i){
			if(q[i].type==1){
				cnt++;
				ans=max(ans,cnt);
			}
			else cnt--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
