//in Windows holy shit...
//比较经典，找一个矩形使位于其边上点最多
//枚举上下两条横线，维护每条竖线的 lft[i] 在两条横线上在竖线左边的点的个数
//on[i]横线(不含)范围内在竖线上的点  on2[i] 横线范围内在竖线上的点
//ans=max(ans,lft[j]-lft[i]+on[i]+on[j])
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100 + 5;
struct Point{
	int x,y;
	bool operator<(const Point& rhs) const {
		return  x<rhs.x;
	}
} p[maxn];
int lft[maxn],on[maxn],on2[maxn],ny[maxn];
int n;


int main()
{
	//freopen("test","r",stdin);
	int kase=0;
	while(scanf("%d",&n)==1 && n){
		for(int i=0;i<n;++i){
			scanf("%d %d",&p[i].x,&p[i].y);
			ny[i]=p[i].y;
		}
		sort(p,p+n);
		sort(ny,ny+n);
		int cnt=unique(ny,ny+n)-ny;
        if(cnt<=2){
			printf("Case %d: %d\n",++kase,n);
			continue;
		}
		int ans=0;
		for(int i=0;i<cnt;++i)
			for(int j=i+1;j<cnt;++j){
				int miny=ny[i],maxy=ny[j];
				int k=0;
				for(int ti=0;ti<n;++ti){
					if(ti==0 || p[ti].x!=p[ti-1].x){
						++k;
						on[k]=on2[k]=0;
						lft[k]= k==0 ?0:lft[k-1]+on2[k-1]-on[k-1];
					}
					if(p[ti].y>miny && p[ti].y<maxy) ++on[k];
					if(p[ti].y>=miny && p[ti].y<=maxy) ++on2[k];
				}
				if(k<=2){
					ans=n;
					break;
				}
				int M=0;
				for(int pj=1;pj<=k;++pj){
                    ans=max(ans,lft[pj]+on2[pj]+M);
                    M=max(M,on[pj]-lft[pj]);
				}
				/*for(int pi=1;pi<=k;++pi)
                    for(int pj=pi+1;pj<=k;++pj)
                        ans=max(ans,lft[pj]-lft[pi]+on[pi]+on2[pj]);*/
			}
		printf("Case %d: %d\n",++kase,ans);
	}
	return 0;
}
