//最大连续子序列推广到三维形式...
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=100+5;
typedef long long ll;
int n,m,h;
ll arr[maxn],mat[maxn][maxn],cub[maxn][maxn][maxn];

//1维序列 O(n)
ll MaxSq(ll arr[],int x,int y,int &l,int &r)
{
	ll cur,res;
	cur=res=arr[x];
	l=r=x;
	for(int i=x+1;i<=y;++i){
		if(arr[i]>cur+arr[i]) l=i;
		cur=max(arr[i],cur+arr[i]);	  //当前最优比之前子序列大则重新更新为从当前值开始
		if(cur>res)	r=i;
		res=max(cur,res);
	}
	//cout<<l<<" "<<r<<endl;
	return res;
}

//2维矩阵 0(n^3)
//先求每列的前缀和，枚举(行)x1,x2, 在 arr[x]=sun[x2]-sum[x1] 转化为1维
ll MaxSm(ll mat[][maxn],int x1,int y1,int x2,int y2,int &l1,int &r1,int &l2,int &r2)
{
	int l,r; 
	for(int j=y1;j<=y2;++j)
		for(int i=x1;i<=x2;++i)
			mat[i][j]+=mat[i-1][j];		//计算前缀和
	ll res,arr[maxn];
	res=mat[x1][y1];
	l1=l2=x1;r1=r2=y1;
	for(int i=x1;i<=x2;++i)
		for(int j=i;j<=x2;++j){
			for(int k=y1;k<=y2;++k) arr[k]=mat[j][k]-mat[i-1][k];
			ll sum=MaxSq(arr,y1,y2,l,r);
			//cout<<sum<<" "<<i<<" "<<j<<endl;
			if(res<sum){
				res=sum;
				l1=i+1;l2=j;
				r1=l;r2=r;
			}
		}
	return res;
}

//3维长方体 O(n^5)
//枚举每层的x1,y1,x2,y2坐标,对x1,y1,x2,y2由下到上的前缀和的长方体求MaxSq;
ll get(ll cub[][maxn][maxn],int x1,int y1,int x2,int y2,int z)
{
	return cub[x2][y2][z]+cub[x1-1][y1-1][z]-cub[x1-1][y2][z]-cub[x2][y1-1][z];
}

ll MaxSc(ll cub[][maxn][maxn],int x1,int x2,int y1,int y2,int z1,int z2)
{
	int l,r;
	for(int i=x1;i<=x2;++i)
		for(int j=y1;j<=y2;++j){
			ll tot=0;
			for(int k=z1;k<=z2;++k){
				tot+=cub[i][j][k];
				cub[i][j][k]=cub[i-1][j][k]+cub[i][j-1][k]-cub[i-1][j-1][k]+tot;
			}
		}
	ll arr[maxn],res=cub[x1][y1][z1];
	for(int i=x1;i<=x2;++i)
		for(int j=i;j<=x2;++j)
			for(int k=y1;k<=y2;++k)
				for(int h=k;h<=y2;++h){
					for(int t=z1;t<=z2;++t) arr[t]=get(cub,i,k,j,h,t)-get(cub,i,k,j,h,t-1);
					res=max(res,MaxSq(arr,z1,z2,l,r));	//此处可以模仿MaxSm求对应坐标,因参数太多暂不予考虑...
				}
	return res;
}

//n维...

int main()
{
	int T;
	//freopen("test","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&m,&h);
		//for(int i=0;i<n;++i) scanf("%lld",&arr[i]); 
		memset(cub,0,sizeof(cub));
		for(int i=1;i<=n;++i) 
			for(int j=1;j<=m;++j)
				for(int k=1;k<=h;++k)
					scanf("%lld",&cub[i][j][k]);
		printf("%lld\n",MaxSc(cub,1,n,1,m,1,h));
		if(T) puts("");
	}
	return 0;
}

