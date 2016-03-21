/*答案是ll，记得输出用 %ld*/
#include<bits/stdc++.h>
using namespace std;

const int inf=0x8fffffff;

int main()
{
	/*freopen("test","r",stdin);
	freopen("1","w",stdout);*/
	int n,kase=1;
	while (cin>>n){
		long long ans=inf;
		int a[20];
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		for(int i=n-1;i>=0;--i)
			for(int j=0;j+i<n;++j){
				long long res=1;
				for(int k=j;k<=i+j;++k)
					res*=a[k];
				ans=max(ans,res);
			}
		if(n==1) ans=a[0];
		printf("Case #%d: The maximum product is %ld.\n\n",kase++,(ans>0)?ans:0);
	}
	return 0;
}
