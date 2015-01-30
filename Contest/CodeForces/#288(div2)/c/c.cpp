#include<bits/stdc++.h>
using namespace std;

const int maxn=300+10;

int main()
{
	//freopen("test","r",stdin);
	bool candle[2*maxn];
	int m,t,r,w[maxn],ans=0;
	memset(candle,0,sizeof(candle));
	cin>>m>>t>>r;
	for(int i=0;i<m;++i){
		int w,cnt=0,cn=0;
		scanf("%d",&w);
		w+=300;
		for(int j=w-t;j<w;++j)
			if(candle[j]) cnt++;
			else cn++; 
		//cout<<cn<<endl;
		if(cnt>=r) continue;
		else if(cn<r-cnt){
			printf("-1\n");
			return 0;
		}else
		{
			cn=r-cnt;	
			for(int j=w-1;j>=w-t;j--){
				if(!cn) break;
				if(!candle[j]){
					candle[j]=1;
					cn--;
				}
			}
		}
	}
	for(int i=0;i<=600;++i) if(candle[i]){
		//cout<<i<<endl;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}

