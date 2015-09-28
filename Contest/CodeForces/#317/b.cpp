#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 1010;
int tj[2][100010];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,s;
	scanf("%d %d",&n,&s);
	memset(tj,0,sizeof tj);
	for(int i=0;i<n;++i)
	{
		char s[2];
		int p,q;
		scanf("%s %d %d",s,&p,&q);
		//printf("%d %d\n",p,q);
		if(s[0] == 'S')
		{
			tj[0][p] += q;
		}
		else
		{
			tj[1][p] += q;
		}
	}
	int cnt = 0;
	vector<pair<int,int> > ans;
	for(int i=0;i<=100000;++i)
	{
		if(tj[0][i])
		{
			ans.push_back(make_pair(i,tj[0][i]));
			//printf("S %d %d\n",i,tj[0][i]);
			++cnt;
		}
		if(cnt==s) break;
	}
	for(int i=ans.size() - 1;i>=0;--i) printf("S %d %d\n",ans[i].first,ans[i].second);
	cnt = 0;
	for(int i=100000;i>=0;--i)
	{
		if(tj[1][i])
		{
			printf("B %d %d\n",i,tj[1][i]);
			++cnt;
		}
		if(cnt==s) break;
	}
	return 0;
}
