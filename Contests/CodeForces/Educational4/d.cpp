#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

vector<pair<int,int> > V,ans;

int main()
{
	//freopen("test.txt","r",stdin);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		V.push_back(make_pair(x,-1));
		V.push_back(make_pair(y,1));
	}
	sort(V.begin(),V.end());
	int lst = 0,cur = 0;
	for(int i=0;i<V.size();++i)
	{
		if(cur == k-1 && V[i].se == -1)
		{
			lst = V[i].fi;
		}
		if(cur == k && V[i].se == 1)
		{
			ans.push_back(make_pair(lst,V[i].fi));
		}
		cur -= V[i].se;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}
