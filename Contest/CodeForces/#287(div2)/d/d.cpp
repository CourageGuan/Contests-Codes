/*WA...*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,m;
	long long ans[1010];
	cin>>n>>k>>m;
	for(int i=0;i<=9;++i) if(i%k==0) ans[0]++;
	if(n<=1) ans[0]--;
	int j=1;
	while(j<n-1){
		for(int i=0;i<=9;++i)
			if((i%k)*(10%k)*(j%k)==0) ans[j]++;
		j++;
	}
	for(int i=1;i<=9;++i) if((i%k)*(10%k)*((n-1)%k)==0) ans[n-1]++;
	long long res=1;
	for(int i=0;i<n;++i){
		res=(res*ans[i])%m;
	}
	cout<<res<<endl;
}

