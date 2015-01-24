#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<long long> path;

int main()
{
	//freopen("test","r",stdin);
	long long h,n;
	cin>>h>>n;
	int h1=h/2,h2=h-h1;
	//if(n >= (1<<(h))) h+=1;
	int d;
	n=(long long)(1<<h1)*(1<<h2)+n-1;
	while(n>1){
		//cout<<n%2<<endl;
		path.pb(n%2);
		n/=2;
	}
	path.pb(1);
	d=path.size();
	long long ans=0;
	for(int i=d-2;i>=0;i--){
		if(path[i]==path[i+1]) ans+=(long long)1<<(h);
		else ans+=1;
		h--;
		//cout<<h<<endl;
		//bit=(bit==0)?1:0;
		//cout<<bit<<endl;
	}
	cout<<ans<<endl;
}


