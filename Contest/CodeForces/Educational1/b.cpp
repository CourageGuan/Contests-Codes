#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string s;
int m,n;

string cal(int l,int r,int k)
{
	k %= (r-l+1);
	if(k == 0) return s;
	else return s.substr(0,l)+s.substr(r-k+1,k)+s.substr(l,r-l+1-k)+s.substr(r+1,n-r-1);
}

int main()
{
	//freopen("test.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>m;
	n = s.size();
	while(m--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		--l;--r;
		s = cal(l,r,k);
	}
	cout<<s<<'\n';
	return 0;
}
