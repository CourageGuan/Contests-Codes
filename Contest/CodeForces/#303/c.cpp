#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int H[maxn],X[maxn];
int d[maxn][3];

int dp(int p,int k){
	if(p==0) return 1;
	int &ans=d[p][k];
	if(ans!=-1) return ans;
	ans=0;

	if(k==0){
		if(X[p]-H[p]>X[p-1]) ans=max(ans,max(dp(p-1,0),dp(p-1,1))+1);
		if(X[p]-H[p]>X[p-1]+H[p-1]) ans=max(ans,dp(p-1,2)+1);
	}

	if(k==1){
		ans=max(dp(p-1,2),max(dp(p-1,0),dp(p-1,1)));
	}

	if(k==2){
		if(X[p]+H[p]<X[p+1]){
		   	ans=max(dp(p-1,0),dp(p-1,1))+1;
			if(X[p]>X[p-1]+H[p-1]) ans=max(ans,dp(p-1,2)+1);
		}
	}

	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d %d",X+i,H+i);
	if(n==1){
	   	puts("1");
		return 0;
	}
	memset(d,-1,sizeof d);
	printf("%d\n",dp(n-1,1)+1);
	return 0;
}
