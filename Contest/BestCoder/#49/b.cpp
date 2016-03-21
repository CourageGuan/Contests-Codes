//WA
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;

const int maxn = 20010;
int p[2*maxn];
string str0;

void gao()
{
	int i;
	int mx = 0;
	int id;
	for(i=1; i<str0.size(); i++)
	{
		if( mx > i )
			p[i] = min( p[2*id-i], mx-i );        
		else
			p[i] = 1;
		for(; str0[i+p[i]] == str0[i-p[i]]; p[i]++) ;
		if( p[i] + i > mx )
		{
			mx = p[i] + i;
			id = i;
		}
	}
}

bool yes()
{
	//cout<<str0<<endl;
	//for(int i=0;i<str0.size();++i) cout<<p[i]; 
	//cout<<endl;
	for(int i=2;i<str0.size();i+=2)
	{
		if(i-p[i]!=0) continue;
		int j = i + p[i];
		int k = j + p[j];
		if(k>=str0.size()) continue;
		if(k+p[k]>=str0.size()) return true;
	}
	return false;
}

int main()
{
	//freopen("test.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		str0.clear();
		str0 += "$#";
		for(int i = 0; i < str.size(); i++)
		{
			str0 += str[i];
			str0 += "#";
		}
		gao();
		puts(yes()?"Yes":"No");
	}
	return 0;
}

