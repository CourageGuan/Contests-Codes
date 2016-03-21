#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;
ll solve(ll a,ll b)
{
	if(a<b) swap(a,b);
	ll ans=0,t;
	while(b>1)
	{
		ans+=a/b;
		a=a%b;
		if(a<b) swap(a,b);
	}
	if(b==1) ans+=a;
	return ans;
}

int main()
{
	ll a,b;
	cin>>a>>b;
	cout<<solve(a,b)<<endl;
	return 0;
}

