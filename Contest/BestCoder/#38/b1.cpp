#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int maxn=200000+10;
int cnt[maxn];


int main()
{
	int T,n,kase=0;
	scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		int mx=0,ans=1;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			int t;scanf("%d",&t);
			mx=max(t,mx);
			++cnt[t];
		}
		for(int i=mx;i>1;--i)
		{
			int t=i,sum=0;
			while(t<=mx){
				if(cnt[t]){
					sum+=cnt[t];
					if(sum>=2) break;
				}
				t+=i;
			}
			if(sum>=2){
				ans=i;
			   	break;
			}
		}
		printf("Case #%d: %d\n",++kase,ans);

	}
	return 0;
}

