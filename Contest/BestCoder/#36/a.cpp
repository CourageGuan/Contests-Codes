#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string s;
bool mp[255];

bool solve()
{
	memset(mp,0,sizeof(mp));
	int len=0;
	char c=s[0];

	for(int i=0;i<s.size();++i)
		if(s[i]==c) len++;
		else break;
	if(3*len!=s.size()) return false;
	for(int j=0;j<s.size();j+=len){
		if(mp[s[j]]) return false;
		else mp[s[j]]=1;
		for(int i=0;i<len;++i) if(s[j+i]!=s[j]) return false;
	}

	return true;
}

int main()
{
	//freopen("test","r",stdin);
	while(getline(cin,s)){
		puts(solve()?"YES":"NO");	
	}
	return 0;
}

