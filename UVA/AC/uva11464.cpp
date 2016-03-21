//枚举量减缩，从枚举整个矩阵改为只枚举第一行，计算下面几行
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define pb push_back

const int maxn=15 + 5;
const int INF=0x3f3f3f3f;
int n,mtx[maxn][maxn],tmp[maxn][maxn];

int cal(int m[][maxn],int i,int j)
{
	int ans=0;
	if(i>1) ans+=m[i-1][j];
	if(i<n) ans+=m[i+1][j];
	if(j>1) ans+=m[i][j-1];
	if(j<n) ans+=m[i][j+1];
	return ans;
}

bool yes(int m[][maxn])
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(cal(m,i,j)&1) return false;
	return true;
}

int main()
{
	//freopen("test","r",stdin);
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;++kase){
		memset(mtx,0,sizeof(mtx));
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&mtx[i][j]);
		vector<int> set;
		for(int i=1;i<=n;++i) if(!mtx[1][i]) set.pb(i);
		int ans=INF,len=1<<set.size();
		for(int i=0;i<len;++i){
			int res=0,cnt=0,bit;
			memcpy(tmp,mtx,sizeof(tmp));
			for(bit=i;bit>0;bit=(bit>>1)){
				if(bit&1){
					res++;
					tmp[1][set[cnt]]=1;
				}
				++cnt;
			}
			bool flag=true;
			for(int k=1;k<n;++k)
				for(int j=1;j<=n;++j){
				if(!(cal(tmp,k,j) & 1)) continue;
				if(!tmp[k+1][j]){
					tmp[k+1][j]=1;
					++res;
					continue;
				}
				flag=false;
				break;
			}
			/*if(flag){
				for(int r=1;r<=n;++r){
					for(int c=1;c<=n;++c) cout<<tmp[r][c]<<" ";
					puts("");
				}
				cout<<res<<endl;
				puts("");
			}*/
			if(flag && yes(tmp)) ans=min(ans,res);
		}
		if(ans>=INF) ans=-1;
		printf("Case %d: %d\n",kase,ans);
	}
	return 0;
}

