#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n,op=0;
	cin>>n>>m;
	if(n>=m){
		cout<<n-m<<endl;
		return 0;
	}
	while(m && m>n){
		if(m&1){
			m++;
			op++;
		}
		m/=2;
		op++;
	}
	cout<<op+(n-m)<<endl;
	return 0;
}
