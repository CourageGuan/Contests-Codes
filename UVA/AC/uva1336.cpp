//不断更新状态区间dp，可以将点视为区间,可知修补的点每一刻都在区间内
//d(i,j,k)记录的是区间[i,j]已修缮,目前在左端点(k=0)或右端点(k=1)
//先将点按位置排序,再记录消耗的前缀和,每过时间T更新区间外的消耗,cost(i,j)表示[i,j]外的消耗
//d(i,j,k)=min(d(i-1,j,k)+cost(i,j)*T,d(i,j+1,k)+cost(i,j)*T)
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1000 + 10;
const double INF=1e9;

struct Point{
	double pos,cur,inc;
	bool operator<(const Point& rhs) const{
		return pos<rhs.pos;
	}
} p[maxn];

int n,vis[maxn][maxn][2];
double d[maxn][maxn][2],cost[maxn],v,pos;

inline double time(double a,double b)
{
	return fabs(a-b)/v;
}

inline double update(int i,int j,double t)
{
	return (cost[i]-cost[0]+cost[n]-cost[j+1])*t;
}

double dp(int i,int j,int k)
{
	double& ans=d[i][j][k];
	if(vis[i][j][k]) return ans;
	vis[i][j][k]=1;
	ans=INF;
	if(i>0){
		if(k==0)
			ans=min(ans,dp(i-1,j,0)+update(i,j,time(p[i-1].pos,p[i].pos)));
		else
			ans=min(ans,dp(i-1,j,0)+update(i,j,time(p[i-1].pos,p[j].pos)));
	}
	if(j<n-1){
		if(k==0)
			ans=min(ans,dp(i,j+1,1)+update(i,j,time(p[j+1].pos,p[i].pos)));
		else
			ans=min(ans,dp(i,j+1,1)+update(i,j,time(p[j+1].pos,p[j].pos)));
	}
	if(ans>=INF) ans=0;
	return ans;
}

int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d %lf %lf",&n,&v,&pos)==3 && n){
		double ans=0;
		for(int i=0;i<n;++i){
		   	scanf("%lf %lf %lf",&p[i].pos,&p[i].cur,&p[i].inc);
			ans+=p[i].cur;
		}
		sort(p,p+n);
		cost[0]=0;
		for(int i=0;i<n;++i)
			cost[i+1]=cost[i]+p[i].inc;
		int cur=0;
		p[n].pos=INF;
		for(int i=0;i<n;++i)
			if(pos>=p[i].pos && pos<=p[i+1].pos){
				cur=i+1;
				break;
			}
		memset(vis,0,sizeof(vis));
		if(cur==0) ans+=dp(0,0,0)+update(0,-1,time(p[0].pos,pos));
		else if(cur==n) ans+=dp(n-1,n-1,0)+update(0,-1,time(p[n-1].pos,pos));
		else ans+=min(dp(cur-1,cur-1,0)+update(0,-1,time(p[cur-1].pos,pos)),dp(cur,cur,0)+update(0,-1,time(p[cur].pos,pos)));

		printf("%d\n",(int)ans);
	}
	return 0;
}

