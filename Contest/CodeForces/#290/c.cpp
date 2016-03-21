/*拓扑排序，根据相邻两个字符串的比较
 确定重排后字母的大小关系，需要注意的是
 aa  	//若不是DAG，则Impossible
 a	 这种情况是Impossible的　*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define Fd(i,a,b) for(int i=(a);i>=(b);--i)

int pic[30][30],vis[30],vi[30];

stack<int> st;

bool dfs(int u)
{
	vis[u]=-1;	//vising
	for(int i=0;i<30;++i)
		if(i!=u && pic[u][i]==1){
			if(vis[i]<0) return false;	//not a DAG
			else if(!vis[i] && !dfs(i)) return false;
		}
	vis[u]=1;
	st.push(u);
	return true;
}

int main()
{
	memset(pic,0,sizeof(pic));
	memset(vis,0,sizeof(vis));
	memset(vi,0,sizeof(vi));
	int n;
	cin>>n;
	string s,last;
	bool flag=true;
	F(i,1,n){
		cin>>s;
		if(i==1){
			last=s;
			continue;
		}
		int len=min(s.size(),last.size())-1;
		if(s.size()<last.size() && last.substr(0,len+1)==s) flag=false;
		F(j,0,len)
			if(s[j]!=last[j]){
				vi[last[j]-'a']=1;
				pic[last[j]-'a'][s[j]-'a']=1;
				break;
				//pic[s[j]-'a'][last[j]-'a']=1;
			}
		last=s;
	}
	F(i,0,25)
		if(!vis[i])
			if(!dfs(i)){
				flag=false;
				break;
			}
	if(!flag){
		puts("Impossible");
		return 0;
	}	
	//F(i,0,25) if(!vi[i]) st.push(i);
	while(!st.empty()){
		printf("%c",'a'+st.top());
		st.pop();
	}
	cout<<endl;
	return 0;
}


