#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 55;
int h[maxn],v[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	int n;		
	memset(h,0,sizeof h);
	memset(v,0,sizeof v);
	vector<int> ans;
	scanf("%d",&n);
	for(int i=0;i<n*n;++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(h[a] || v[b]) continue;
		h[a] = v[b] = 1;
		ans.push_back(i+1);
	}
	for(int i=0;i<ans.size();++i)
		printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
	return 0;
}
