#include<stdio.h>
#include<iostream>
using namespace std;

int cal(int n)
{
	int cnt=1;
	while(n!=1){
		if(n&1) n=3*n+1;
		else n/=2;
		++cnt;
	}
	return cnt;
}

int main()
{
	//for(int i=22;i<=22;++i) printf("%d\n",cal(i));
	int i,j;
	while(~scanf("%d %d",&i,&j)){
		int ans=0;
		for(int k=min(i,j);k<=max(i,j);++k) ans=max(ans,cal(k));
		printf("%d %d %d\n",i,j,ans);
	}

	return 0;
}
