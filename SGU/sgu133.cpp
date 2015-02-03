/*sgu的水题确实不错，这道题坑了好久*/
#include<iostream>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair 
#define fi first
#define se second
vector<pair<int,int> > v;

int main()
{
	int n,ans=0;
	int x,y;
	cin>>n;
	v.clear();
	for(int j=0;j<n;++j){
		bool flag=false;
		cin>>x>>y;
		for(int i=0;i<v.size();++i){
			if(x>v[i].fi && y<v[i].se){
				ans++;
				flag=true;
				break;
			}else if(x<v[i].fi && y>v[i].se){
				ans++;
				v[i].fi=-1;
				v[i].se=-1;
			}
		}
		if(!flag) v.pb(mp(x,y));
	}
	cout<<ans<<endl;
	return 0;
}
