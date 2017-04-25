#include<iostream>
using namespace std;

const long long mod=1e9+7;

int main()
{
	long long ans[7];
	long long a,b,n;
	while(cin>>a>>b>>n){
		ans[1]=a;
		ans[2]=b;
		ans[3]=b-a;
		ans[4]=-a;
		ans[5]=-b;
		ans[6]=a-b;
		n=(n%6+6)%6;
		if(n==0) n=6;
		cout<<(ans[n]%mod+mod)%mod<<endl;
	}
	return 0;
}
