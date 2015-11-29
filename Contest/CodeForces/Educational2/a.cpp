#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
char cstr[maxn];
vector<string> ans[2];

bool yes(const string& s)
{
	if(s.size() == 1 && s[0] == '0') return true;
 	if(s.size() ==0 || s[0] == '0') return false;
	for(int i=0;i<s.size();++i) if(s[i] > '9' || s[i] < '0') return false;
	return true;
}

int main()
{
	//freopen("test.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s",cstr);
	string s(cstr),ss="";


	for(int i=0;i<s.size();++i)
	{
		if(s[i] == ',' || s[i] == ';' || i == s.size()-1)
		{
			if(i == s.size()-1 && s[i] != ',' && s[i]!=';') ss += s[i];
			if(yes(ss))
				ans[0].push_back(ss);
			else
				ans[1].push_back(ss);
			if(i == s.size()-1 && (s[i] == ',' || s[i] == ';')) ans[1].push_back("");
			ss = "";
		}
		else ss += s[i];
	}

	if(ans[0].size() == 0) 
		puts("-");
	else
	{
		putchar('\"');
		for(int i=0;i<ans[0].size();++i)
		{
			printf("%s%s",i == 0?"":",",ans[0][i].c_str());
		}
		puts("\"");
	}

	if(ans[1].size() == 0) 
		puts("-");
	else
	{
		putchar('\"');
		for(int i=0;i<ans[1].size();++i)
		{
			printf("%s%s",i == 0?"":",",ans[1][i].c_str());
		}
		puts("\"");
	}
	return 0;
}

