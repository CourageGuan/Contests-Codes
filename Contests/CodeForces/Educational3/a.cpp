#include<bits/stdc++.h>
using namespace std;

vector<int> V;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		V.push_back(x);
	}
	sort(V.begin(),V.end(),greater<int>());
	int sum = 0;
	for(int i=0;i<V.size();++i)
	{
		sum += V[i];
		if(sum >= m)
		{
			printf("%d\n",i+1);
			break;
		}
	}
	return 0;
}
