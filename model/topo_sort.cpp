#include<stack>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn=12345;
int G[maxn][maxn],vis[maxn],n=maxn;
stack<int> st;

void init()
{
	memset(G,0,sizeof(G));
	memset(vis,0,sizeof(vis));
	while(!st.empty()) st.pop();
}

bool dfs(int u)
{
	vis[u]=-1;	//vising
	for(int i=0;i<n;++i)
		if(i!=u && G[u][i]){
			if(vis[i]<0) return false;	//not a DAG
			else if(!vis[i] && !dfs(i)) return false;
		}
	vis[u]=1;
	st.push(u);
	return true;
}

			 
int main()
{
	init();
	for(int i=0;i<n;i++)
		if(!vis[i])
			if(!dfs(i)){
				puts("Not a DAG!");
				return 0;
			}
	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
	return 0;	
}



