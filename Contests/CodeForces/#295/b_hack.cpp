#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n,op=0;
	cin>>n>>m;
	if(n>m){
		cout<<n-m<<endl;
		return 0;
	}
	int x=m;
	while(x!=n){
		if(x&1){
			x++;
		}else x/=2;
		op++;
		if(x<n){
			op+=(n-x);
			break;
		}
	}
	cout<<op<<endl;
	return 0;
}
