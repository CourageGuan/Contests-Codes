/*找不出目前算法缺陷，WA*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define pb push_back 

const int maxn=10000+100;

bool col[maxn][maxn];
int ans[maxn];

void init()
{
	memset(col,0,sizeof(col));
}

int main()
{
	//freopen("test","r",stdin);
	int n,m,cnt=0;
	while(scanf("%d%d",&n,&m)==2){
		init();
		vector<int> pic[maxn];
		for(int i=0;i<m;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			pic[a].pb(b);pic[b].pb(a);
		}
		int od=0;
		for(int i=1;i<=n;++i) od=max(od,(int)pic[i].size());
		od+=(od&1)?0:1;
		for(int i=1;i<=n;++i){
			int c;
			for(int j=1;j<=od;++j) 
				if(!col[i][j]){
					c=j;
					break;
				}
			ans[i]=c;
			for(int j=0;j<pic[i].size();++j){
				int k=pic[i][j];
				col[k][c]=1;
			}
		}
		if(cnt++) puts("");
		printf("%d\n",od);
		for(int i=1;i<=n;++i) printf("%d\n",ans[i]);
	}
	return 0;
}


