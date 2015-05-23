#include<bits/stdc++.h>
using namespace std;

const int maxn=6010;
typedef long long ll;
int vis[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	int n;	
	memset(vis,0,sizeof vis);
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		++vis[x];
	}
	int ans=0;
	for(int i=0;i<=maxn;++i){
		if(vis[i]>1){
			ans+=vis[i]-1;
			vis[i+1]+=vis[i]-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
