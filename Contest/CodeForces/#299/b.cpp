#include<bits/stdc++.h>
using namespace std;

vector<int> pos;

void dfs(long long n){
	if(n>1e9) return;
	pos.push_back(n);
	dfs(n*10+4);
	dfs(n*10+7);
}

int main()
{
	dfs(0);
	sort(pos.begin(),pos.end());
	int n;
	scanf("%d",&n);
	for(int i=0;i<pos.size();++i)
		if(pos[i]==n){
			printf("%d\n",i);
			break;
		}
	return 0;
}

