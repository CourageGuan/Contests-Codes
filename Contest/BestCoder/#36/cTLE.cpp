#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int nextInt()
{
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	int res=0;
	while(isdigit(c)){
		res=res*10+c-'0';
	   	c=getchar();
	}
	return res;	
}

const int maxn=50000 + 10;
int n,q;
int h[maxn];

int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d %d",&n,&q)==2){
		for(int i=0;i<n;++i) h[i]=nextInt();
		int ans;
		for(int i=0;i<q;++i){
			int j,t=nextInt();
			j=ans=0;
			while(j<n){
				while(j<n && t>=h[j]) ++j;
				if(j<n) ++ans;
				while(j<n && t<h[j]) ++j;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

