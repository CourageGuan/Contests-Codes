#include<bits/stdc++.h>
using namespace std;

const int maxn=110;
bool vis[maxn];
vector<int> ans;

int main()
{
	//freopen("test.txt","r",stdin);
	int n,x,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		vis[i]=1;
		for(int j=0;j<n;++j){
			scanf("%d",&x);
			if(x==1 || x==3) vis[i]=0;
		}
		if(vis[i]) ++cnt;
	}
	printf("%d\n",cnt);
	for(int i=0;i<n;++i){
		if(vis[i]){
			printf("%d",i+1);
			if(--cnt) printf(" ");
		}
	}
	return 0;
}
