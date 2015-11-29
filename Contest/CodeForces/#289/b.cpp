#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k,pe[110];
	cin>>n>>k;
	int mn=101,mx=0;
	for(int i=0;i<n;++i){
		cin>>pe[i];
		mn=min(mn,pe[i]);
		mx=max(mx,pe[i]);
	}
	if(mx-mn>k){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=0;i<n;++i){
		int m=pe[i];
		int a[110];
			for(int i=0;i<m;++i) a[i]=i%k+1;
			sort(a,a+m);
			for(int i=0;i<m;++i){
				if(i) cout<<" ";
				cout<<a[i];
			}
			cout<<endl;
		}
	return 0;
}
