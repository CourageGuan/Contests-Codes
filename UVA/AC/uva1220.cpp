//树形dp最大独立集
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

const int maxn=200 + 10; 	
int cnt,n,d[maxn][2],f[maxn][2];

vector<int> sons[maxn];

map<string,int> id;
inline int ID(const string& s){
	if(!id.count(s)) id[s]= cnt++;
	return id[s];
}

void init()
{
	cnt=0;
	for(int i=0;i<n;++i) sons[i].clear();
	id.clear();
}

int dp(int u,int k)
{
	f[u][k]=1;
	d[u][k]=k;
	for(int i=0;i<sons[u].size();++i){
		int v=sons[u][i];
		if(k==1){
			d[u][1] += dp(v,0);
			if(!f[v][0]) f[u][k]=0;
		}
		else{
			d[u][0] += max(dp(v,0),dp(v,1));
			if(d[v][0]==d[v][1]) f[u][k]=0;
			else if(d[v][0]>d[v][1] && !f[v][0]) f[u][k]=0;
			else if(d[v][1]>d[v][0] && !f[v][1]) f[u][k]=0;
		}
	}
	return d[u][k];
}

int main()
{
	//freopen("test","r",stdin);
	ios::sync_with_stdio(false);
	string s,ss;
	while(cin>> n && n){
		cin >> s;
		init();
		ID(s);
		for(int i=1;i<n;++i){
		   	cin>>s>>ss;
			sons[ID(ss)].push_back(ID(s));
		}
		printf("%d ",max(dp(0,1),dp(0,0)));
		bool flag=0;
		if(d[0][0]>d[0][1] && f[0][0]) flag=1;
		if(d[0][1]>d[0][0] && f[0][1]) flag=1;
		puts(flag?"Yes":"No");
	}
	return 0;
}


