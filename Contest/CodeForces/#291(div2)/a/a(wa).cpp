#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long ans=0,i=0;
	while(n){
		if(n==9){
			ans+=9*pow(10,i++);
			break;
		}
		ans+=((n%10>=5)?(9-n%10):(n%10))*pow(10,i++);
		n/=10;
	}
	cout<<ans<<endl;
	return 0;
}
