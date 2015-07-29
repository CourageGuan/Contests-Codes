#include<bits/stdc++.h>

using namespace std;
const int maxn = 100010;

int main()
{
	//freopen("test.txt","r",stdin);
	int n,k,ans=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;++i){
		int t,x,pre=-1,cnt=0;
		scanf("%d",&t);
		for(int j=0;j<t;++j){
			scanf("%d",&x);
			if(x==1 || pre!=-1){
				if(pre==-1){
					++cnt;
					pre=x;
					continue;
				}
				if(pre!=x-1){
					++cnt;
					pre=-1;
					continue;
				}
				pre=x;
			}else ++cnt;
		}
//		cout<<cnt<<endl;
		ans+=2*cnt-1;
	}
	printf("%d\n",ans-1);
	return 0;
}



