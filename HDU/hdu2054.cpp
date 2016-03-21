//看似水但不水...
//大数，前导0，正负号，浮点。。。都得考虑到...
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

string trans(string s)
{
	string res;
	res.clear();
	int first=1;
	bool flag=false;
	for(int i=0;i<s.size();++i){
		if(s[i]!='0' || !first) res.push_back(s[i]);
		if(s[i]!='0' && s[i]!='-') first=0;
		if(s[i]=='.') flag=true;
	}
	if(flag){
		int i=res.size()-1;
		for(;i>=0;--i) if(res[i]!='0') break;
		if(res[i]=='.') --i;
		res.resize(i+1);
	}
	return res;
}

int main()
{
	string a,b;
	while(cin>>a>>b){
		//cout<<trans(a)<<" "<<trans(b)<<endl;
		puts(trans(a)==trans(b)?"YES":"NO");
	}
	return 0;
}
