#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

set<int> save;
int a,n;

int bfs()
{
	queue<int> Q;
	queue<int> S;
	Q.push(a);
	S.push(0);
	set<int>::iterator it;
	while(!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		int d = S.front(); S.pop();
		if(cur == 0) return d;
		for(it = save.begin(); it != save.end();  ++it)
		{
			if((*it)>cur) break;
			Q.push(cur%(*it));
			S.push(d+1);
		}
	}
	return -1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		save.clear();
		scanf("%d %d",&n,&a);
		bool flag = false;
		for(int i=0;i<n;++i)
		{
			int b;
			scanf("%d",&b);
			if(flag) continue;
			if(b<=a){
				if(a%b == 0) flag = true;
			   	save.insert(b);
			}
		}
		if(flag) puts("1");
		else
		{
			printf("%d\n",bfs());
		}
	}
	return 0;
}

