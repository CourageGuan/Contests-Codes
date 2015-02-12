/*哈夫曼编码，数据不大可以用优先队列*/
#include<bits/stdc++.h>
using namespace std;

const int maxn=5000+5;

int main()
{
	//freopen("test","r",stdin);
	int n;
	while(cin>>n && n){
		int a[maxn];
		memset(a,0,sizeof(a));
		for(int i=0;i<n;++i) cin>>a[i];
		sort(a,a+n);
		queue<int> q;
		long long ans=0;
		int k=0;
		for(int i=1;i<n;++i){
			int t,b;
			if(!q.empty() && (q.front()<a[k] || k>=n)){
				t=q.front();
				q.pop();
			}
			else{
				t=a[k];
				k++;
			}
			if(!q.empty() && (q.front()<a[k] || k>=n)){
				b=q.front();
				q.pop();
			}
			else{
				b=a[k];
				k++;
			}
			ans+=t+b;
			q.push(t+b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

