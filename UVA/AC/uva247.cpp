//floyd 求传递闭包
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
using namespace std;

const int maxn=30;
map<string,int> id;
map<int,string> name;
int pic[maxn][maxn];
int n,m;

void init()
{
	name.clear();
	id.clear();
	memset(pic,0,sizeof(pic));
}

void solve()
{
	bool vis[maxn];
	memset(vis,0,sizeof(vis));
	for(int k=1;k<=n;++k)	
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				pic[i][j]=pic[i][j] || (pic[i][k] && pic[k][j]);
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			vis[i]=1;
			printf("%s",name[i].c_str());
			for(int j=1;j<=n;++j){
				if(pic[i][j] && pic[j][i] && !vis[j]){
					vis[j]=1;
					printf(", %s",name[j].c_str());
				}
			}
			puts("");
		}
}


int main()
{
	//freopen("test","r",stdin);
	//freopen("1","w",stdout);
	int kase=0;
	while(scanf("%d %d",&n,&m)==2 && n){
		if(kase) puts("");
		int cnt=1;
		init();
		string s1,s2;
		for(int i=0;i<m;++i){
			cin>>s1>>s2;
			if(!id[s1]){
				name[cnt]=s1;
				id[s1]=cnt++;
			}
			if(!id[s2]){
				name[cnt]=s2;
				id[s2]=cnt++;
			}
			pic[id[s1]][id[s2]]=1;
		}
		printf("Calling circles for data set %d:\n",++kase);
		solve();
	}
	return 0;
}

