#include<bits/stdc++.h>
using namespace std;

queue<int> q[2];
int INF=100001;

int main()
{
//	freopen("test.txt","r",stdin);
	int n,t,x;
	scanf("%d",&n);
	for(int i=0;i<2;++i){
		scanf("%d",&t);
		for(int j=0;j<t;++j){	
			scanf("%d",&x);
			q[i].push(x);
		}
	}
	t=0;
	while(t<INF){
		if(q[0].empty() || q[1].empty()){
			printf("%d %d\n",t,q[0].empty()?2:1);
			return 0;
		}
		int p1=q[0].front(),p2=q[1].front(); q[0].pop(); q[1].pop();
		if(p1>p2){
			q[0].push(p2);
			q[0].push(p1);
		}else{
			q[1].push(p1);
			q[1].push(p2);
		}
		++t;
	}
	printf("-1\n");
	return 0;
}
