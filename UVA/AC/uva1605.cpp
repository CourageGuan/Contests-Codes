/*构造法☻*/
#include<bits/stdc++.h>
using namespace std;

const char country[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	int n;
	while(cin>>n){
		cout<<2<<" "<<n<<" "<<n<<endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				cout<<country[i];
			cout<<endl;
		}
		cout<<endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				cout<<country[j];
			cout<<endl;
		}
	}
	return 0;
}
