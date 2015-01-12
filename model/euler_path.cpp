#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;

const int maxn=12345;
stack<int,int> st;
int G[maxn][maxn],vis[maxn][maxn],vised[maxn],n=maxn,begin,end;

void init()
{
	memset(G,0,sizeof(G));
	memset(vis,0,sizeof(vis));
	memset(vised,0,sizeof(vised));
	while(!st.empty()) st.pop();
}

void is_link(int u)
{
	vised[u]=1;
	for(i=1;i<=n;++i)
		if(G[u][i] && u!=i) is_link(i);
}

bool is_euler()
{
	int flag=0;
	for(i=1;i<=n;++i){ 			//有向图int degree=0,begin,end;
		int degree=0;			//     	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j)		//			for(j=1;j<=n;++j){
			if(i!=j && G[i][j])	//				if(G[i][j]) degree--;
				degree++;		//				if(G[j][i]) degree++;
		if(degree & 1) 			//			}
		{						//		if(degree && abs(degree)!=1) return false;
			flag++;				//		else (degree==-1)begin=i:end=i;
			(begin):end=i:begin=i;//
		}
		if(flag>2) return false; 
	}
	is_link(begin);
	for(i=1;i<=n;++i)
		if(!vised[i]) return false;
	return true;
}

void euler(int u)
{
	for(int i=1;i<=n;++i)
		if(G[u][i] && !vis[u][i]){
			vis[u][i]=vis[i][u]=1;	//有向图  vis[u][i]=1;
			euler(i);
			printf("%d %d\n",u,i);	//逆序输出st.push(u,i);
		}
}

int main()
{
	init();
	if(is_euler())
		euler(begin);	
	return 0;
}



