/*搜索+剪枝(0.222->0.079)*/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ok puts("ok")
#define SETS(st) while(!st.empty()) st.pop();

const int maxn=30;
const int inf=0x7fffffff;
int n,vis[maxn],mn;
int pic[maxn][maxn];
set<int> nodes;
string a;
stack<string> st;
stack<int> stt;


void init()
{
	nodes.clear();
	a.clear();
	memset(vis,0,sizeof(vis));
	memset(pic,0,sizeof(pic));
	SETS(st);
	SETS(stt);
	mn=inf;
}

int cal(string s,int n)
{
	int t=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			if(i==j) continue;
			if(pic[(int)(s[i]-64)][(int)(s[j]-64)])	t=max(t,abs(j-i));
	}
	return t;
}

void solve(int cur)
{
	if(cur==n){
		if(st.empty()){
			mn=cal(a,n);
			st.push(a.c_str());
			stt.push(cal(a,n));
		}
		else{
			if(stt.top()>cal(a,n)){
				//cout<<a.c_str()<<cal(a)<<endl;
				mn=cal(a,n);
				st.push(a.c_str());
				stt.push(cal(a,n));
			}
		}
		return;
	}
	for(set<int>::iterator it=nodes.begin();it!=nodes.end();++it){
		if(!vis[*it]){
			char ch=(*it)+64;
			a[cur]=ch;
			if(cal(a,cur+1)>=mn) break;
			vis[*it]=1;
			solve(cur+1);
			vis[*it]=0;
		}
	}
}

void print()
{
	string s=st.top();
	int ans=stt.top();
	for(int i=0;i<n;++i)
		printf("%c ",s[i]);
	printf("-> %d\n",ans);
}

int main()
{
	//freopen("test","r",stdin);
	string s;
	while(getline(cin,s) && s[0]!='#'){
		init();
		while(s.find(';')!=-1){
			int pos=s.find(';');
			string ss=s.substr(0,pos);
			nodes.insert(ss[0]-64);
			for(int i=2;i<ss.size();++i){
				pic[ss[0]-64][ss[i]-64]=1;
				pic[ss[i]-64][ss[0]-64]=1;
				nodes.insert(ss[i]-64);
			}
			s.erase(0,pos+1);
		}
		nodes.insert(s[0]-64);
		for(int i=2;i<s.size();++i){
			pic[s[0]-64][s[i]-64]=1;
			pic[s[i]-64][s[0]-64]=1;
			nodes.insert(s[i]-64);
		}
		n=nodes.size();
		//cout<<n<<endl;
		/*for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)
				cout<<pic[i][j]<<" ";
			cout<<endl;
		}*/
		solve(0);
		print();
	}
	return 0;
}

