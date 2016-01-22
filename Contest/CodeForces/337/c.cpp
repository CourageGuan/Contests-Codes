#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string cal(string s)
{
	string res = "";
	for(int i=0;i<s.size()/2;++i)	
		if(s[i] == '+') res += '*';
		else res += '+';
	for(int i=s.size()/2;i<s.size();++i)	
		if(s[i] == '+') res += '+';
		else res += '*';
	return res;
}


int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	string s[10][1000];

	s[2][0]="++**";
	s[2][1]="+*+*";
	s[2][2]="++++";
	s[2][3]="+**+";


	scanf("%d",&n);
	if(n == 0)
	{
		puts("*");
		return 0;
	}
	if(n == 1)
	{
		puts("++");
		puts("+*");
		return 0;
	}
	if(n == 2)
	{
		for(int i=0;i<4;++i) puts(s[n][i].c_str());
		return 0;
	}
	for(int i=3;i<=9;++i)
	{
		int n = i;
		int m = pow(2,n-1);
		for(int i=0;i<m;++i)
		{
			s[n][i] = s[n-1][i] + s[n-1][i];
		}
		for(int i=0;i<m;++i)
		{
			s[n][i+m] = cal(s[n][i]);
		}
	}
	for(int i=0;i<pow(2,n);++i) puts(s[n][i].c_str());
	return 0;
}
