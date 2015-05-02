#include<stdio.h>
#include<set>
#include<string.h>
#include<math.h>
using namespace std;

const int maxn=100000+10;
int cnt[maxn];

int main()
{
	int T,n;
	scanf("%d",&T);
	for(int kase=1;kase<=T;++kase){
		memset(cnt,0,sizeof cnt);
		scanf("%d",&n);
		int mx=1;
		for(int i=0;i<n;++i){
			int t;
			scanf("%d",&t);
			int m=(int)sqrt(t+0.5);
			if(cnt[t]) mx=max(mx,t);
			else ++cnt[t];
			for(int i=2;i<=m;++i){
				if(t%i) continue;
				int j=t/i;
				if(cnt[i]) mx=max(mx,i);
				else ++cnt[i];
				if(cnt[j]) mx=max(mx,j);
				else ++cnt[j];
			}
		}
		printf("Case #%d: %d\n",kase,mx);
	}
	return 0;
}


