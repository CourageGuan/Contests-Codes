#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 3e5 + 10;
int a[maxn],n;
set<int> vis;
vector<pair<int,int> > ans;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	int lst = 1;
	for(int i=0;i<n;++i)
	{
		if(vis.find(a[i]) != vis.end())
		{
			vis.clear();
			ans.push_back(make_pair(lst,i+1));
			lst = i+2;
		}
		else vis.insert(a[i]);
	}
	if(!ans.size()) puts("-1");
	else
	{
		ans[ans.size()-1].second = n;
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i) printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
