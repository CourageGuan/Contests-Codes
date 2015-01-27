/*这是一个错误的解法，但是通过了undebug的random数据...*/
#include<bits/stdc++.h>
using namespace std;

const int maxn=1000+10;
int pic[maxn][maxn],vis[maxn],vs[maxn][maxn],hav[maxn];
int v,e,t,tot;


void init()
{
	memset(pic,0,sizeof(pic));
	memset(vis,0,sizeof(vis));
	memset(vs,1,sizeof(vs));
	memset(hav,0,sizeof(hav));
}

void dfs(int u)
{
	//cout<<u<<endl;
	for(int i=1;i<=v;++i)
		if(pic[u][i] && !vs[u][i] ){
			vs[u][i]=vs[i][u]=1;
			tot++;
			hav[i]--;
			dfs(i);
			//tot--;
			break;
		}
}

void dfs2(int u)
{
	for(int i=1;i<=v;++i)
		if(pic[u][i] && !vs[u][i]){
			vs[u][i]=vs[i][u]=1;
			tot++;
			//hav[i]--;
			//cout<<i<<endl;
			dfs2(i);
		}
}

void solve()
{
	int ans=0,cnt=0;
	for(int i=1;i<=v;++i){
		//cout<<i<<" "<<vis[i]<<endl;
		if(vis[i] & 1){
			hav[i]--;
			tot=0;
			dfs(i);
			//cout<<tot<<endl;
			//cout<<endl;
			if(!tot) continue;
			ans+=tot;
			if(cnt++) ans++;
		}
	}
	/*for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j)
			if(!vs[i][j]) cout<<i<<" "<<j<<endl;*/
	//cout<<ans<<endl;
	cnt=0;
	for(int i=1;i<=v;++i){
		//cout<<i<<" "<<hav[i]<<endl;
		if(hav[i]){
			//cout<<i<<" "<<hav[i]<<endl;
			//hav[i]--;
			tot=0;
			dfs2(i);
			//cout<<endl;
			if(!tot) continue;
			ans+=tot;
			if(cnt++) ans++;	//Here wrong!!
		}
	}
	printf("%d\n",ans*t);
}

int main()
{
	//freopen("test","r",stdin);
	//freopen("1","w",stdout);
	int kase=1;
	while(scanf("%d%d%d",&v,&e,&t)==3 && v ){
		printf("Case %d: ",kase++);
		init();
		for(int i=0;i<e;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			pic[a][b]=pic[b][a]=1;
			vis[a]++;
			vis[b]++;
			hav[a]=vis[a];
			hav[b]=vis[b];
			//cout<<a<<" "<<b<<endl;
			vs[a][b]=vs[b][a]=0;
		}
		solve();
	}
	return 0;
}


