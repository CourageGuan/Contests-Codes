#include<cstdio>
#include<queue>
using namespace std;


int main()
{
	int n;
	while(scanf("%d",&n)==1 && n){
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=0;i<n;++i){
			int a;
			scanf("%d",&a);
			q.push(a);
		}
		long long ans=0;
		for(int i=1;i<n;++i){
			int a,b;
			a=q.top();q.pop();
			b=q.top();q.pop();
			q.push(a+b);
			ans+=a+b;
		}
		printf("%d\n",ans);
	}
	return 0;
}
