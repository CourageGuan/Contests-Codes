#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 110;
char s[maxn];
int n;
vector<int> ans;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",s);
	int cur = 0;
	F(i,0,n)
	{
		if(i == n || s[i] == 'W')
		{
			if(cur) ans.push_back(cur);
			cur = 0;
		}
		else cur++;
	}
	printf("%d\n",ans.size());
	for(auto it:ans) printf("%d ",it);
	return 0;
}
