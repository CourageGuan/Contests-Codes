#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=110;
int save[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;++i) scanf("%d",save+i);
		sort(save,save+n);
		int k,cnt=0;
		scanf("%d",&k);
		int s=unique(save,save+n)-save;
		if(n-s>=k)
			printf("%d\n",s);
		else 
			printf("%d\n",s-(k-n+s));
	}
	return 0;
}

