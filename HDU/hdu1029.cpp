#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;

map<int,int> dic;

int main()
{
	int n;
	while(~scanf("%d",&n)){
		int x,ans=0;
		dic.clear();
		for(int i=0;i<n;++i){
			scanf("%d",&x);
			++dic[x];
			if(!ans && dic[x]>=(n+1)/2) ans=x;
		}
		printf("%d\n",ans);
	}
	return 0;
}
