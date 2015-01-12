#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<set>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;++i)

map<string,string> mp;
set<string> st;

int main()
{
	int q,cnt=0;
	mp.clear();
	cin>>q;
	F(i,1,q){
		string s1,s2;
		cin>>s1>>s2;
		bool flag=true;
		for(set<string>::iterator it=st.begin();it!=st.end();++it){
			string s=*it;
			while(mp[s]!="##")
				s=mp[s];
			if(s==s1){
				flag=false;
				break;
			}
		}
		mp[s1]=s2;
		mp[s2]="##";
		if (flag){
			st.insert(s1);
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for(set<string>::iterator it=st.begin();it!=st.end();++it){
		string s=*it;
		while(mp[s]!="##")
			s=mp[s];
		cout<<*it<<" "<<s<<endl;
	}
	return 0;
}
		
