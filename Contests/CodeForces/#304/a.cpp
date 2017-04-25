#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
typedef long long ll;

int main()
{
	//freopen("test.txt","r",stdin);
	ll n,w,k,s;
	cin>>k>>n>>w;
	s=((1+w)*w)/2*k;
	s-=n;
	cout<<(max(0LL,s))<<endl;
	return 0;
}
