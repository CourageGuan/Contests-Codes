#include<bits/stdc++.h>
using namespace std;

map<string,string> dic1;
map<string,string> dic2;
int main()
{
	//ios::sync_with_stdio(false);
	string s1,s2;
	int n,m;
	scanf("%d %d",&n,&m);
	while(m--){
		cin>>s1>>s2;
		dic1[s1]=s2;
		dic2[s2]=s1;
	}
	string s;
	while(n--){
		cin>>s;
		if(dic1.count(s)) if(s.size()<=dic1[s].size()) cout<<s;
		else cout<<dic1[s];
		else if(dic2.count(s)) if(s.size()<dic2[s].size()) cout<<s;
		else cout<<dic2[s];
		if(n) cout<<" ";
	}
	cout<<endl;
	return 0;
}
