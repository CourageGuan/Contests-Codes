#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define Fd(i,a,b) for(int i=(a);i>=(b);--i)

int main()
{
	int m,n;
	cin>>m>>n;
	F(i,1,m){
		if(i&1){
			F(j,1,n) cout<<"#";
			cout<<endl;
			continue;
		}
		else if(i/2 &1){
			F(j,1,n-1) cout<<".";
			cout<<"#"<<endl;
			continue;
		}else{
			cout<<"#";
			F(j,1,n-1) cout<<".";
			cout<<endl;
			continue;
		}
	}
	return 0;
}
