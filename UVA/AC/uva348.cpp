#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef long long ll;
const int maxn=100 + 5;
const int INF=0x3f3f3f3f;
int n,m[maxn];
ll d[maxn][maxn];
int p[maxn][maxn];


ll dp(int i,int j)
{
	if(i==j) return 0;
	ll &ans=d[i][j];
	if(ans) return ans;
	ans=INF;
	for(int k=i;k<j;++k)
		ans=min(ans,dp(i,k)+dp(k+1,j)+m[i-1]*m[k]*m[j]);
	return ans;
}

ll dp()
{
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;++i) d[i][i]=0;
	for(int L=2; L<=n;++L)
		for(int i=1; i<=n-L+1 ; ++i){
			int j=i+L-1;
			d[i][j]=INF;
			for(int k=i;k<j;++k){
				ll t=min(d[i][j],d[i][k]+d[k+1][j]+m[i-1]*m[k]*m[j]);
				if(d[i][j]>t){
					d[i][j]=t;
					p[i-1][j]=k;
				}
			}
		}
	return d[1][n];
}

vector<int> ans;

void print(int i,int j)
{
	if(!p[i][j]) return ;
	print(i,p[i][j]);
	print(p[i][j],j);
	ans.push_back(p[i][j]);
	printf("%d ",p[i][j]);
}

int main()
{
	freopen("test","r",stdin);
	int kase=0;
	while(scanf("%d",&n) && n){
		int t;
		scanf("%d",&m[0]);
		for(int i=1;i<n;++i) scanf("%d %d",&m[i],&t);
		scanf("%d",&m[n]);
		dp();
		ans.clear();
		printf("Case %d: ",++kase);
		print(0,n);
		int l[maxn],r[maxn];
		int pl[maxn],pr[maxn];
		for(int i=1;i<=n;++i) pl[i]=pr[i]=i;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for(int j=0;j<ans.size();++j){
			int i=ans[j];
			int lf=pl[i];
			int rt=pr[pr[i]+1];
			pr[lf]=rt;
			pl[rt]=lf;
			/*for(int k=lf;k<=rt;++k){
				pl[k]=lf;
				pr[k]=rt;
			}*/
			l[lf]++;
			r[rt]++;
		}
		//puts("");
		//for(int i=1;i<=n;++i) cout<<l[i]<<" "<<r[i]<<endl;
		for(int i=1;i<=n;++i){
			while(l[i]){
				printf("(");--l[i];
			}
			printf("A%d",i);
			while(r[i]){
				printf(")");--r[i];
			}
			if(i<n) printf(" x ");
		}
		puts("");
	}
	return 0;
}


