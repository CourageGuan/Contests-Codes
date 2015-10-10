//分块思想
//将平面分为若干10^3 * 10^6 的矩形 ，在每个矩形内按y排序，按照矩形编号分别按照升序降序排序
//可以简单证明这样最长的manhattan距离和即
#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 10;
const int B = 1000;

vector<pair<int,int> > order[maxn/B + 10];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		order[x/B].push_back(make_pair(y,i));
	}
	vector<int> ans;
	for(int i=0;i<=maxn/B;++i)
	{
		sort(order[i].begin(),order[i].end());
		if(!(i&1))
			reverse(order[i].begin(),order[i].end());
		for(int j=0;j<order[i].size();++j)
			ans.push_back(order[i][j].second);
	}
	for(int i=0;i<ans.size();++i) printf("%d%c",ans[i]+1,i==ans.size()-1?'\n':' ');
	return 0;
}
