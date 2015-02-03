/*水题*/
#include<iostream>
using namespace std;

int fib[50];

int main()
{
	int n;
	fib[1]=fib[2]=1;
	fib[0]=0;
	cin>>n;
	long long ans=1;
	for(int i=1;i<n;++i){
		fib[i+1]=fib[i]+fib[i-1];
		ans+=fib[i+1];
	}
	cout<<ans<<endl;
	return 0;
}
