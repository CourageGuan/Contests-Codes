#include<cstdio>
#include<iostream>
#include<cstring>
#include<set> 
using namespace std;

const int maxn=200000 + 10;

struct Edge{
	int a,b;
	Edge(int a,int b):a(a),b(b) {}
	bool operator<(const Edge& rhs) const {
		return a<rhs.a || (a==rhs.a && b<rhs.b);
	}
} ;

set<Edge> ss;
int h1[255],h2[255];

int main()
{
	int n,dis=0;
	char s[maxn],t[maxn];
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%s",t);
	memset(h1,0,sizeof(h1));
	memset(h2,0,sizeof(h2));
	for(int i=0;i<n;++i)
		if(s[i]!=t[i]){
			++h1[s[i]];
			++h2[t[i]];
			++dis;
		}
	bool flag=false;
	int tem;
	for(int i='a';i<='z';++i)
		if(h1[i] && h2[i]){
			tem=i;
			flag=true;
			break;
		}
	if(!flag){
		cout<<dis<<endl;
		cout<<-1<<" "<<-1<<endl;
		return 0;
	}
	int p1,p2;
	ss.clear();
	for(int i=0;i<n;++i){
		if(s[i]==t[i]) continue;
		if(ss.count(Edge(t[i],s[i]))){
			cout<<dis-2<<endl;
			int j;
			for(j=i-1;j>=0;--j) if(t[i]==s[j] && s[i]==t[j]) break;
			cout<<i+1<<" "<<j+1<<endl;
			return 0;
		}
		ss.insert(Edge(s[i],t[i]));
		if(tem==s[i]) p1=i;
		if(tem==t[i]) p2=i;
	}
	cout<<dis-1<<endl;
	cout<<p1+1<<" "<<p2+1<<endl;
	return 0;
}
