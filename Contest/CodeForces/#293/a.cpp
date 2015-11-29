#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("test","r",stdin);
	string s1,s2;
	cin>>s1>>s2;
	int pos=s1.size()-1;
	while(s1[pos]=='z') pos--;
	if(pos>=0){
		for(int i=pos+1;i<s1.size();++i) s1[i]='a';
		s1[pos]+=1;
	}
	if(pos<0 || s1>=s2){
		puts("No such string");
		return 0;
	}
	cout<<s1<<endl;
	return 0;
}

