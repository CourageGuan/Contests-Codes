#include<bits/stdc++.h>
using namespace std;

#define N 5000000
const int maxn=5000010;
int vis[maxn];
int res[maxn];

void init(){
	memset(res,0,sizeof res);
	memset(vis,0,sizeof vis);
	for(int i=2;i<=N;++i){
		if(!vis[i]){
			++vis[i];
			for(int j=i+i;j<=N;j+=i){
				int t=j;
				while(t%i==0){
					t/=i;
					++vis[j];
				}
			}
		}
		res[i]+=res[i-1]+vis[i];
	}
}

int a,b;

int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&a,&b);
		printf("%d\n",res[a]-res[b]);
	}
	return 0;
}

