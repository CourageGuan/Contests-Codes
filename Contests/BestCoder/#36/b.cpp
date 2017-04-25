#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

const int maxn=1000*1000+10;
int n,m;
int h[maxn];
set<int> has;

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


int main()
{
	//freopen("test","r",stdin);
	while(scanf("%d %d",&n,&m)==2){	
		has.clear();
		for(int i=0;i<n;++i) h[i]=nextInt();
		sort(h,h+n);
		for(int j=0;j<m;++j){
			int t=nextInt();
			if(has.find(t)!=has.end()) putchar('0');
			else{
				has.insert(t);
				printf("%ld",upper_bound(h,h+n,t)-lower_bound(h,h+n,t));
			}
			putchar('\n');
		}
	}
	return 0;
}

