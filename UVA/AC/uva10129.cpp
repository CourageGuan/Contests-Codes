<<<<<<< HEAD
/*将单词视为一条有向路径,判断是否构成欧拉回路，一是判断是否是回路，二是判断节点的入度和出度*/
=======
>>>>>>> 9b556abebc914e12bdab6aad3c40becb755945b4
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define F(i,a,b) for(int (i)=(a);(i)<=(b);++(i))

const int maxn=30;
const int n=26;
int G[maxn][maxn],vis[maxn][maxn],node[maxn];

void init()
{
	memset(G,0,sizeof(G));
	memset(vis,0,sizeof(vis));
	memset(node,0,sizeof(node));
}

int id(char ch){return ch-96;}

void read()
{
	int m;
	cin>>m;
	while(m--){
		string s;
		cin>>s;
		G[id(s[0])][id(s[s.size()-1])]++;
		vis[id(s[0])][id(s[s.size()-1])]++;
		node[id(s[0])]++;
		node[id(s[s.size()-1])]++;
	}
}

void dfs(int u,int v[][maxn]){
	F(i,1,n)
		if(G[u][i] && v[u][i]){
			v[u][i]--;
			dfs(i,v);
		}
}

bool solve()
{
	bool flag=true;
	int star[maxn],cnt=0;
	F(i,1,n)
		if(node[i]&1) star[cnt++]=i;
	if(cnt>2) return false;
	if(!cnt){
		int star;
		F(i,1,n) 
			if(node[i]){
			   star=i;
			   break;
			}
	dfs(star,vis);
	F(i,1,n)
		F(j,1,n) if(vis[i][j]) return false;
	}
	else if(cnt==1){
		int* p=&vis[0][0];
		dfs(star[0],vis);
		F(i,1,n)
			F(j,1,n) if(vis[i][j]) return false;
	}
	else{
		int tmp[maxn][maxn],flag=2;
		memcpy(tmp,vis,sizeof(tmp));
		int *p1=&vis[0][0],*p2=&tmp[0][0];
		/*F(i,1,n){
			F(j,1,n){cout<<vis[i][j];} 
				//if(vis[i][j]){flag--;break;}
			//if(flag==1) break;
			cout<<endl;
		}*/
		dfs(star[0],vis);	
		dfs(star[1],tmp);
		F(i,1,n){
			F(j,1,n)//{cout<<vis[i][j];} 
				if(vis[i][j]){flag--;break;}
			if(flag==1) break;
		}
		int f=flag;
		F(i,1,n){
			F(j,1,n)if(tmp[i][j]){flag--;break;}
			if(flag==f-1) break;
		}
		return flag;
	}
	return true;
}


int main()
{
	//freopen("test","r",stdin);
	int kase;
	cin>>kase;
	while(kase--){
		init();
		read();
		if(solve()) puts("Ordering is possible.");
		else puts("The door cannot be opened.");
	}
	return 0;
}
		
