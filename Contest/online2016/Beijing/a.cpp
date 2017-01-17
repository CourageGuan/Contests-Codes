#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define endl '\n'

string s;
struct String{
	string s;
	bool operator<(const String &rhs) const
	{
		int p = s.find('/'),q = rhs.s.find('/');
		if((p != s.size() -1 && q != rhs.s.size()-1) || 
			(p == s.size() -1 && q == rhs.s.size()-1))
			return s < rhs.s;
		else
			return (p != s.size() - 1);
		return 0;
	}
	bool operator==(const String &rhs) const
	{
		return s == rhs.s;
	}
};
vector<String> v;

void print(int n)
{
	for(int i=0;i<n;++i) cout << ' ';
}

void dfs(int d,vector<String> v)
{
	sort(v.begin(),v.end());
	string prv = v[0].s.substr(0,v[0].s.find('/')),lst = v[0].s;
	vector<String> vv;
	for(int i=0;i<v.size();++i)
	{
		string it = v[i].s;
		if(i && it == lst) continue;
		int p = it.find('/');
		string cur = it.substr(0,p);
		cout << "!" << cur << ' ' << prv << ' ' << it << endl;
		if(cur != prv || i == v.size()-1)
		{
			print(d);
			cout << prv << endl;
			if(vv.size()) dfs(d+4,vv);
			vv.clear();
		}
		else vv.push_back((String){it.substr(p+1,it.size())});
	}
}

int main()
{
	freopen("test.txt","r",stdin);
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	int z = 1;
	while(getline(cin,s))
	{
		if(s == "0")
		{
			printf("Case %d:\n",z++);
			dfs(0,v);
			v.clear();
		}
		else
			v.push_back((String){s+"/"});
	}
	return 0;
}
