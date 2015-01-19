#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

string s;

bool pal(string s){
	F(i,0,s.size()/2)
		if(s[i]!=s[s.size()-1-i]) return false;
	return true;
}

bool solve()
{
	F(i,0,s.size()){
		string s1=s.substr(0,i),s2=s.substr(i,s.size());
		F(j,0,25){
			char ch=97+j;
			string ss=s1+ch+s2;
			if(pal(ss)){
				cout<<ss<<endl;
				return true;
			}
		}
	}
	F(j,0,25){
		char ch=97+j;
		string ss=s+ch;
		if(pal(ss)){
			cout<<ss<<endl;
			return true;
		}
	}
	return false;
}

int main()
{
	cin>>s;
	if(!solve()) puts("NA");
	return 0;
}


