/*O(nlogn) set判重 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;

const int maxn=1000000+5;

//bool v[1000000000+1];
set<int> vis;
int a[maxn];

int main()
{
	//freopen("test","r",stdin);
	int kase;
	cin>>kase;
	while(kase--){
		vis.clear();
		//memset(v,0,sizeof(v));
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		int l=0,r=0,ans=0;
		while(r<n){
			//cout<<l<<" "<<r<<endl;
			if(/*!v[a[r]]*/!vis.count(a[r])){
				//v[a[r]]=1;
				vis.insert(a[r]);
				r++;
			}
			else while(/*v[a[r]]*/vis.count(a[r])) /*v[a[l++]]=0;*/vis.erase(a[l++]);
			ans=max(ans,r-l);
		}
		printf("%d\n",ans);
	}
	return 0;
}



