/*等效，类似于noip 2013 D2 T1 */
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n && n){
		long long ans=0,cur=0;
		for(int i=0;i<n;++i){
			int m;
			cin>>m;
			ans+=abs(cur);
			cur+=m;
		}
		cout<<ans<<endl;
	}
	return 0;
}
