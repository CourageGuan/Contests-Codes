/*这种每个元素端节点的题目都可以抽象成图论，如A+B+0000,抽象成边A+B-和B+A-
 然后拓扑排序看有没有环,这种题见得多了就好做了*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define Ft(i,a,b) for(int i=(a);i<=(b);i+=2)

const int maxn=100;
int pic[maxn][maxn],vis[maxn];

bool topo(int u)
{
	vis[u]=-1;
	F(i,1,54)
		if(pic[u][i]){
			if(vis[i]<0) return true;
			else if(!vis[i] && topo(i)) return true;
		}
	vis[u]=1;
	return false;
}


int main()
{
	//freopen("test","r",stdin);
	int n;
	while(cin>>n){
		memset(pic,0,sizeof(pic));
		memset(vis,1,sizeof(vis));
		while(n--){
			string s;
			cin>>s;
			Ft(j,0,7){
				int a;
				a=(s[j+1]=='+')?s[j]-64:s[j]-64+26;
				if (s[j]=='0') a=0;
				Ft(k,0,7){
					if(k==j) continue;
					int b;
					b=(s[k+1]=='+')?s[k]-64+26:s[k]-64;
					if (s[k]=='0') b=0;
					pic[a][b]=1;
					vis[a]=vis[b]=0;
					//cout<<a<<" "<<b<<endl;
				}
			}
		}
		bool flag=false;
		F(i,1,54)
			if(!vis[i]){
				if(topo(i)){
					flag=true;
					break;
				}
			}
		puts((flag)?"unbounded":"bounded");
	}
	return 0;
}


