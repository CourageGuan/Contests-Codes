/*经典的状态图搜索...状态的表示和判重是以后学习的重点*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int v[3],dis;
	bool operator <(const Node& b) const{
		return dis>b.dis;
	}
};

const int maxn=200+5;
int vis[maxn][maxn],ans[maxn],cap[3];

void update(const Node &u)
{
	for(int i=0;i<3;++i){
		int d=u.v[i];
		if(ans[d]<0 || u.dis<ans[d]) ans[d]=u.dis;
	}
}

void solve(int a,int b,int c,int d)
{
	cap[0]=a; cap[1]=b; cap[2]=c;
	memset(ans,-1,sizeof(ans));
	memset(vis,0,sizeof(vis));
	priority_queue<Node> q;
	Node start; 
	start.dis=0; start.v[0]=0; start.v[1]=0; start.v[2]=c;
	q.push(start);
	vis[0][0]=1;
	while(!q.empty()){
		Node u=q.top();q.pop();
		update(u);
		if(ans[d]>=0) break;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j){
				if(i==j) continue;
				if(u.v[i]==0 || u.v[j]==cap[j]) continue;
				int water=min(u.v[i],cap[j]-u.v[j]);
				Node v;
				memcpy(&v,&u,sizeof(u));
				v.dis=u.dis+water;
				v.v[i]-=water;
				v.v[j]+=water;
				if(!vis[v.v[0]][v.v[1]]){
					vis[v.v[0]][v.v[1]]=1;
					q.push(v);
				}
			}
	}

	while(d>=0){
		if(ans[d]>=0){
			printf("%d %d\n",ans[d],d);
			return;
		}
		--d;
	}
}
				

int main()
{
	int kase;
	scanf("%d",&kase);
	while(kase--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		solve(a,b,c,d);
	}
	return 0;
}

