/*枚举二叉树，尚不完全清楚，此题需再理解一下*/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back

struct Tree{
	double lch,rch;
	Tree():lch(0),rch(0) {}
};

const int maxn=1<<6+10;
int s,vis[maxn];
double r,w[maxn],ww[10];
vector<Tree> tree[maxn];


void init()
{
	memset(vis,0,sizeof(vis));
	memset(w,0,sizeof(w));
}

void cal(int subset)
{
	if (vis[subset]) return;
	vis[subset]=1;
	bool have_children=false;
	for(int lft=(subset-1)&subset ; lft ; lft=(lft-1)&subset){	//Important! foreach subset,
		have_children=true;
		int rgt=lft^subset;
		double d1=w[rgt] / w[subset];
		double d2=w[lft] / w[subset];
		cal(lft);
		cal(rgt);
		for(int i=0;i<tree[lft].size();i++)
			for(int j=0;j<tree[rgt].size();j++){
				Tree t;
				t.lch=max(tree[lft][i].lch+d1,tree[rgt][j].lch-d2);
				t.rch=max(tree[rgt][j].rch+d2,tree[lft][i].rch-d1);
				if(t.lch+t.rch<r) tree[subset].pb(t);
			}
	}
	if(!have_children) tree[subset].pb(Tree());
		
}
	

int main()
{
	int kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%lf",&r);
		scanf("%d",&s);
		init();
		for(int i=0;i<s;++i)
			scanf("%lf",&ww[i]);
		for(int i=0;i<(1<<s);++i){
			tree[i].clear();
			int t=i;
			for(int j=0;j<s;++j){
				w[i]+=((t&1)?ww[j]:0);
				t=t>>1;
			}
			//cout<<w[i]<<endl;
		}
		int ALL=(1<<s)-1;
		cal(ALL);
		double ans=-1;
		for(int i=0;i<tree[ALL].size();++i)
			ans=max(ans,tree[ALL][i].lch+tree[ALL][i].rch);
		printf("%.15lf\n",ans);
	}
}


