#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

string smallest(string s) 
{
	if (s.length()&1) return s;
	string s1 = smallest(s.substr(0,s.length()/2));
	string s2 = smallest(s.substr(s.length()/2,s.length()));
	if (s1 < s2) return s1 + s2;
	else return s2 + s1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1,s2;
	cin>>s1>>s2;
	s1 = smallest(s1);
	s2 = smallest(s2);
	puts(s1 == s2?"YES":"NO");
	return 0;
}
