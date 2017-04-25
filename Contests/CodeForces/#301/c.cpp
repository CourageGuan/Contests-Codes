//dp d[j][k] 表示前j个格子被占，有k个bug的方案数目 
//d[j][k]= d[j][k] + d[j-1][k-a[i]]  j>0 && k-a[i]>=b
//边界d[j][j*a[1]] j∈(0,m)
//答案为 d[m][0..b]
#include<bits/stdc++.h>
using namespace std;

const int maxn=550;
int n,m,b,mod; 
int d[maxn][maxn],a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d",&n,&m,&b,&mod);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		for(int j=0;j<=m;++j) for(int k=0;k<=b;++k){
			if(i==1){
				if(j*a[i]<=b)
					d[j][j*a[i]]=1;
			}
			else if(j>0 && k>=a[i]) d[j][k]+=d[j-1][k-a[i]];
			d[j][k]%=mod;
		}
	}
	int ans=0;
	for(int i=0;i<=b;++i) ans=(ans+d[m][i])%mod;
	printf("%d\n",ans);
	return 0;
}
